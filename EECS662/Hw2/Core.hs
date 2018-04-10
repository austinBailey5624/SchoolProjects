module Core where

--------------------------------------------------------------------------------
-- Core syntax
--------------------------------------------------------------------------------
import Data.Map (Map)
import qualified Data.Map as Map

type Ident = String
data Core = CInt Integer | CAdd Core Core | CMult Core Core
          | CBool Bool | CIs0 Core | CIf Core Core Core
          | CVar Ident | CLam Ident CType Core | CApp Core Core | CLet Ident Core Core
          | CPair Core Core | CLetPair Ident Ident Core Core
          | CUnit | CLetUnit Core Core
          | CInl CType CType Core | CInr CType CType Core
          | CCase Core (Ident, Core) (Ident, Core)
          | CFix Core
          | CRef Core | CGet Core | CPut Core Core
  deriving (Eq, Show)
--shouldn't ref take an int?
data CType = CTInt | CTBool | CTFun CType CType
           | CTProd CType CType | CTOne
           | CTSum CType CType
           | CTRef CType
  deriving (Eq, Show)

--------------------------------------------------------------------------------
-- Typing and type checking
--------------------------------------------------------------------------------

type TEnv = [(Ident, CType)]

check :: TEnv -> Core -> Maybe CType
check _ (CInt _) =
    return CTInt
check g (CAdd e1 e2) =
    do CTInt <- check g e1
       CTInt <- check g e2
       return CTInt
check g (CMult e1 e2) =
    do CTInt <- check g e1
       CTInt <- check g e2
       return CTInt
check _ (CBool _) =
    return CTBool
check g (CIs0 e) =
    do CTInt <- check g e
       return CTBool
check g (CIf e1 e2 e3) =
    do CTBool <- check g e1
       t2 <- check g e2
       t3 <- check g e3
       if t2 == t3 then return t2 else Nothing
check g (CVar x) =
    lookup x g
check g (CLam x t1 e) =
    do t2 <- check ((x, t1):g) e
       return (CTFun t1 t2)
check g (CApp e1 e2) =
    do CTFun t1 t2 <- check g e1
       t1' <- check g e2
       if t1 == t1' then return t2 else Nothing
check g (CLet x e1 e2) =
    do t <- check g e1
       check ((x, t) : g) e2
check g (CPair e1 e2) =
    do t1 <- check g e1
       t2 <- check g e2
       return (CTProd t1 t2)
check g (CLetPair x1 x2 e1 e2) =
    do CTProd t1 t2 <- check g e1
       check ((x1, t1) : (x2, t2) : g) e2
check g CUnit =
    return CTOne
check g (CLetUnit e1 e2) =
    do CTOne <- check g e1
       check g e2
check g (CInl t1 t2 e) =
    do t <- check g e
       if t == t1 then return (CTSum t1 t2) else Nothing
check g (CInr t1 t2 e) =
    do t <- check g e
       if t == t2 then return (CTSum t1 t2) else Nothing
check g (CCase e (x1, e1) (x2, e2)) =
    do CTSum t1 t2 <- check g e
       u1 <- check ((x1, t1) : g) e1
       u2 <- check ((x2, t2) : g) e2
       if u1 == u2 then return u1 else Nothing
check g (CFix f) =
    do CTFun t (CTFun u v) <- check g f
       if t == CTFun u v then return t else Nothing


--do we need to rewrite everything so that it works with a Map instead of a [(Ident, CType)]?

--whats the difference between ref and put?
--is it correct that ref keeps track of the keys, and put
--actually adds them to the Map?
check g (CRef f) =
    Map.size g ( ) ( )--size takes two arguments and I'm not sure why

check g (CGet f) =
    do Map.lookup f g
--don't I need to handle two cases, one where f is in g
--and one where I return nothing?

--is the idea of Core analogous to Value?
--For instance, should the enviornment be from CInts to Cores
--Instead of the example program where it would be Cint to Value?
check g (CPut f h) =
    do Core <- check g h
    do Map.insert f h g
        return CTOne --need to return unit. Is this unit?

--------------------------------------------------------------------------------
-- Evaluation
--------------------------------------------------------------------------------

data Value = VInt Integer | VBool Bool | VFun VEnv Ident Core
           | VPair Value Value | VUnit
           | VInl Value | VInr Value
           | VRef Integer
  deriving (Eq, Show)

run r = r

type VEnv = [(Ident, Value)]

eval :: VEnv -> Map -> Core -> Value
eval _ g (CInt x) =
    VInt x
eval h g (CAdd e1 e2) =
    let VInt x1 = eval h e1
        VInt x2 = eval h e2 in
    VInt (x1 + x2)
eval h g (CMult e1 e2) =
    let VInt x1 = eval h e1
        VInt x2 = eval h e2 in
    VInt (x1 * x2)
eval _ g (CBool b) =
    VBool b
eval h g (CIs0 e) =
    let VInt x = eval h e in
    VBool (x == 0)
eval h g (CIf e1 e2 e3) =
    let VBool b = eval h e1 in
    if b then eval h e2 else eval h e3
eval h g (CVar x) =
    let Just v = lookup x h in v
eval h g (CLam x _ e) =
    VFun h x e
eval h g (CApp e1 e2) =
    let VFun h' x e = eval h e1
        v = eval h e2 in
    eval ((x, v) : h') e
eval h g (CLet x e1 e2) =
    let v1 = eval h e1 in
    eval ((x,v1) : h) e2
eval h g (CPair e1 e2) =
    let v1 = eval h e1
        v2 = eval h e2 in
    VPair v1 v2
eval h g (CLetPair x1 x2 e1 e2) =
    let VPair v1 v2 = eval h e1 in
    eval ((x1, v1) : (x2, v2) : h) e2
eval h g CUnit =
    VUnit
eval h g (CLetUnit e1 e2) =
    let VUnit = eval h e1 in
    eval h e2
eval h g (CInl _ _ e) =
    let v = eval h e in
    VInl v
eval h g (CInr _ _ e) =
    let v = eval h e in
    VInr v
eval h g (CCase e (x1, e1) (x2, e2)) =
    let v = eval h e in
    case v of
      VInl w -> eval ((x1, w) : h) e1
      VInr w -> eval ((x2, w) : h) e2
eval h g (CFix f) =
    VFun h "$x" (CApp (CApp f (CFix f)) (CVar "$x"))

--my work starts here
eval h g (CRef f) = (Map.size g) + 1


eval h (CGet f) =


eval h ()

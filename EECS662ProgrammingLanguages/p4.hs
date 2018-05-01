{-# LANGUAGE GADTs #-}

-- Austin Bailey 2550099 a604b997@ku.edu

import Text.ParserCombinators.Parsec
import Control.Monad
import Text.ParserCombinators.Parsec.Language
import Text.ParserCombinators.Parsec.Expr
import qualified Text.ParserCombinators.Parsec.Token as Token

-- Calculator language extended with an environment to hold defined variables

data TFBAE where
  TNum :: TFBAE
  TBool :: TFBAE
  (:->:) :: TFBAE -> TFBAE -> TFBAE
  deriving (Show,Eq)

data FBAE where
  Num :: Int -> FBAE
  Plus :: FBAE -> FBAE -> FBAE
  Minus :: FBAE -> FBAE -> FBAE
  Mult :: FBAE -> FBAE -> FBAE
  Div :: FBAE -> FBAE -> FBAE
  Bind :: String -> FBAE -> FBAE -> FBAE
  Lambda :: String -> TFBAE -> FBAE -> FBAE
  App :: FBAE -> FBAE -> FBAE
  Id :: String -> FBAE
  Boolean :: Bool -> FBAE
  And :: FBAE -> FBAE -> FBAE
  Or :: FBAE -> FBAE -> FBAE
  Leq :: FBAE -> FBAE -> FBAE
  IsZero :: FBAE -> FBAE
  If :: FBAE -> FBAE -> FBAE -> FBAE
  Fix :: FBAE -> FBAE
  deriving (Show,Eq)

-- Value defintion for statically scoped eval

data FBAEVal where
  NumV :: Int -> FBAEVal
  BooleanV :: Bool -> FBAEVal
  ClosureV :: String -> TFBAE -> FBAE -> Env -> FBAEVal
  deriving (Show,Eq)

-- Enviornment for statically scoped eval

type Env = [(String,FBAEVal)]

-- Statically scoped eval

evalM :: Env -> FBAE -> (Maybe FBAEVal)
evalM e (Num x) = return (NumV x);
evalM e (Plus a b) = do{
    (NumV a2) <- evalM e a;
    (NumV b2) <- evalM e b;
    return (NumV (a2 + b2));
}
evalM e (Minus l r) = do{
    (NumV l2) <- evalM e l;
    (NumV r2) <- evalM e r;
    return (NumV (l2-r2));
}
evalM e (Mult l r) = do{
    (NumV l2) <- evalM e l;
    (NumV r2) <- evalM e r;
    return (NumV (l2*r2));
}
evalM e (Div l r) = do{
    (NumV l2) <- evalM e l;
    (NumV r2) <- evalM e r;
    return (NumV (div l2 r2));
}
evalM e (Bind i v b)= do{
    v' <- evalM e v;
    evalM ((i,v'):e) b
}
evalM e (Lambda i t b)=do{
    return (ClosureV i t b e);
}
evalM e (App f a)=do{
    v <- evalM e a;
    (ClosureV i t b e') <- evalM e f;
    evalM ((i,v):e') b;
}
evalM e (Id i)=do{
    lookup i e;
}
evalM e (Boolean b) = return (BooleanV b);
evalM e (And l r) = do{
    (BooleanV x) <- evalM e l;
    (BooleanV y) <- evalM e r;
    return (BooleanV ( x && y));
}
evalM e (Or l r) = do{
    (BooleanV x) <- evalM e l;
    (BooleanV y) <- evalM e r;
    return (BooleanV (x || y));
}
evalM e (Leq l r) = do{
    (NumV x)<- evalM e l;
    (NumV y)<- evalM e r;
    return (BooleanV (x<=y));
}
evalM e (IsZero x) = do{
    (NumV x2) <- evalM e x;
    return (BooleanV (x2 == 0));
}
--evalM e (If c t e2) = do{
--    (BooleanV x) <- evalM e c;
--    if(x)
--        then (t);
--        else (e2);
--}
evalM e (If c t e2) = do{
    (BooleanV x) <- evalM e c;
    t2 <- evalM e t;
    e3 <- evalM e e2;
    if(x)
        then return t2;
        else return e3;
}
evalM e (Fix f)= do{
    (ClosureV i t b e2) <- evalM e f;
    evalM e (subst i (Fix (Lambda i t b))  b)
}

-- Type inference function

type Cont = [(String,TFBAE)]

typeofM :: Cont -> FBAE -> (Maybe TFBAE)
typeofM ctx (Num x) = return TNum;
typeofM ctx (Plus l r)= do{
    tl <- typeofM ctx l;
    tr <- typeofM ctx r;
    if(tl == TNum && tr == TNum)
        then return TNum;
        else Nothing;
}
typeofM ctx (Minus l r)= do{
    tl <- typeofM ctx l;
    tr <- typeofM ctx r;
    if(tl == TNum && tr == TNum)
        then return TNum;
        else Nothing;
}
typeofM ctx (Mult l r)= do{
    tl <- typeofM ctx l;
    tr <- typeofM ctx r;
    if(tl == TNum && tr == TNum)
        then return TNum;
        else Nothing;
}
typeofM ctx (Div l r)= do{
    tl <- typeofM ctx l;
    tr <- typeofM ctx r;
    if(tl == TNum && tr == TNum)
        then return TNum;
        else Nothing;
}
typeofM ctx (Bind i v b) = do{
    tv <- typeofM ctx v;
    typeofM ((i,tv):ctx) b;
}
typeofM ctx (Lambda i t b) = do{
    r <- typeofM ((i,t):ctx) b;
    return (t:->:r);
--    return (t (:->:) r);
}
typeofM ctx (App f a) = do{ -- f function a argument
    (d:->:r) <- typeofM ctx f;--d domain, r range
    at <- typeofM ctx a;
    if(at==d)
        then return r;
        else Nothing;
}
typeofM ctx (Id x) = do{
    lookup x ctx;
}
typeofM ctx (Boolean x) = return TBool;
typeofM ctx (And l r) = do{
    tl <- typeofM ctx l;
    tr <- typeofM ctx r;
    if(tl == TBool && tr == TBool)
        then return TBool;
        else Nothing;
}
typeofM ctx (Or l r) = do{
    tl <- typeofM ctx l;
    tr <- typeofM ctx r;
    if(tl == TBool && tr == TBool)
        then return TBool;
        else Nothing;
}
typeofM ctx (Leq a b) = do{
    ta <- typeofM ctx a;
    tb <- typeofM ctx b;
    if(ta == TNum && tb == ta)
        then return TBool;
        else Nothing;
}
typeofM ctx (IsZero x) = do{
    tx <- typeofM ctx x;
    if(tx == TNum)
        then return TBool;
        else Nothing;
}
typeofM ctx (If c t e) = do{
    tc <- typeofM ctx c;
    tt <- typeofM ctx t;
    te <- typeofM ctx e;
    if(tc == TBool)
        then
            if( te == tt)
                then return te;
                else Nothing;
        else Nothing;
}
typeofM _ _ = Nothing


-- Interpreter

interp :: FBAE -> (Maybe FBAEVal)
interp x = do{
    typeofM [] x;--checks that it types, if Nothing falls out
    evalM [] x;
}
interp _ = Nothing


subst :: String -> FBAE -> FBAE -> FBAE

subst i v (Num x) = (Num x)

subst i v (Boolean x) = (Boolean x)

subst i v (Plus l r) =
    (Plus (subst i v l) (subst i v r))

subst i v (Minus l r) =
    (Minus (subst i v l) (subst i v r))

subst i v (Mult l r) =
    (Mult (subst i v l) (subst i v r))

subst i v (Div l r) =
    (Div (subst i v l) (subst i v r))

subst i v (App l r) =
    (App (subst i v l) (subst i v r))

subst i v (Lambda i2 t b) =
    (Lambda i2 t (subst i v b))
--    (Lambda (subst i v i2) (subst i v t) (subst i v b))

subst i v (And l r) =
    (And (subst i v l) (subst i v r))

subst i v (Or l r) =
    (Or (subst i v l) (subst i v r))

subst i v (Leq l r) =
    (Leq (subst i v l) (subst i v r))

subst i v (Bind i2 v2 b) =
    if(i == i2)
        then (Bind i2 (subst i v v2) b)
        else (Bind i2 (subst i v v2) (subst i v b))

--subst i v (Id x) = error "!" -- shouldn't evaluate an Id ouside of a bind

subst i v (Id x) = if(i==x) then v else (Id x)

subst i v (IsZero x) = IsZero (subst i v x)

subst i v (If c t e) = If (subst i v c) (subst i v t) (subst i v e)

subst i v (Fix a) = Fix (subst i v a)

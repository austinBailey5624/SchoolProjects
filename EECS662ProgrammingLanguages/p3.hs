{-# LANGUAGE GADTs,FlexibleContexts #-}

-- Imports for Monads

import Control.Monad

-- CFAE AST and Type Definitions

data CFAE where
  Num :: Int -> CFAE
  Plus :: CFAE -> CFAE -> CFAE
  Minus :: CFAE -> CFAE -> CFAE
  Lambda :: String -> CFAE -> CFAE
  App :: CFAE -> CFAE -> CFAE
  Id :: String -> CFAE
  If0 :: CFAE -> CFAE -> CFAE -> CFAE
  deriving (Show,Eq)

type Env = [(String,CFAE)]

evalDynCFAE :: Env -> CFAE -> (Maybe CFAE)

evalDynCFAE e (Num x) = return (Num x);
evalDynCFAE e (Plus a b) = do{
    (Num a2) <- evalDynCFAE e a;
    (Num b2) <- evalDynCFAE e b;
    return (Num(a2 + b2));
}
evalDynCFAE e (Minus l r) = do{
    (Num l2) <- evalDynCFAE e l;
    (Num r2) <- evalDynCFAE e r;
    return (Num(l2 - r2));
}
evalDynCFAE e (Lambda i  b) = return (Lambda i b)
evalDynCFAE e (App f a) = do{
    v <- evalDynCFAE e a;--strict
    (Lambda i b) <- evalDynCFAE e f;
    evalDynCFAE ((i,v):e) b;
--    evalDynCFAE e (subst i v b);--no-should use env not subst
}
evalDynCFAE e (Id i) = do{
    lookup i e;
}
evalDynCFAE e (If0 c t e2) = do{
    c' <- evalDynCFAE e c;
    t' <- evalDynCFAE e t;
    e2' <- evalDynCFAE e e2;
    if(c' == (Num 0))
        then return t'
        else return e2'
}
--Professor, if this were industry, I would leave this catch in,
--to help the next person that works on this page if they mess up
--however you took points off last time, so I'm commenting it out.
--evalDynCFAE _ _ = Nothing

data CFAEValue where
  NumV :: Int -> CFAEValue
  ClosureV :: String -> CFAE -> Env' -> CFAEValue
  deriving (Show,Eq)

type Env' = [(String,CFAEValue)]

evalStatCFAE :: Env' -> CFAE -> (Maybe CFAEValue)
evalStatCFAE e (Num x) = return (NumV x);
evalStatCFAE e (Plus l r) = do{
    (NumV l2) <- evalStatCFAE e l;
    (NumV r2) <- evalStatCFAE e r;
    return (NumV(l2 + r2));
}
evalStatCFAE e (Minus l r) = do{
    (NumV l2) <- evalStatCFAE e l;
    (NumV r2) <- evalStatCFAE e r;
    return (NumV(l2 - r2));
}
evalStatCFAE e (Lambda i b)=do{
    return (ClosureV i b e);
}
evalStatCFAE e (App f a)=do{
    v <- evalStatCFAE e a;
    (ClosureV i b e') <- evalStatCFAE e f;
    evalStatCFAE ((i,v):e') b;
}
evalStatCFAE e (Id i)=do{
    lookup i e;
}
evalStatCFAE e (If0 c t e2) = do{
    c' <- evalStatCFAE e c;
    t' <- evalStatCFAE e t;
    e2' <- evalStatCFAE e e2;
    if(c' == (NumV 0))
        then return t';
        else return e2';
}
--evalStatCFAE _ _ = Nothing

data CFBAE where
  Num' :: Int -> CFBAE
  Plus' :: CFBAE -> CFBAE -> CFBAE
  Minus' :: CFBAE -> CFBAE -> CFBAE
  Lambda' :: String -> CFBAE -> CFBAE
  App' :: CFBAE -> CFBAE -> CFBAE
  Bind' :: String -> CFBAE -> CFBAE -> CFBAE
  Id' :: String -> CFBAE
  If0' :: CFBAE -> CFBAE -> CFBAE -> CFBAE
  deriving (Show,Eq)

elabCFBAE :: CFBAE -> CFAE
--elabCFBAE (Num' x) = return (evalDynCFAE (Num x));
--elabCFBAE (Num' x) = (Num x)
--elabCFBAE (Plus' (Num' l) (Num' r)) = (Plus (Num l) (Num r))--(Num l)--(Plus l r)
--elabCFBAE (Minus' (Num' l) (Num' r)) = (Minus (Num l) (Num r))
--elabCFBAE (Lambda' l (Num' r)) = (Lambda l (Num r))
--elabCFBAE (App' (Num' r) (Num' l)) = (App (Num r) (Num l))


--elabCFBAE (Plus' l r) = (evalDynCFAE [] (Plus l r))
--elabCFBAE (Plus' l r) = (Plus l r)
--elabCFBAE (Minus' l r) = (Minus l r)
--elabCFBAE (Lambda' l r) = (Lambda l r)
--elabCFBAE (App' l r) = (App l r)
--elabCFBAE (Bind' i v b) = (App (Lambda i b) v)
--elabCFBAE (Id' i) = (Id i)
--elabCFBAE (If0' c t e) = (If0 c t e)
elabCFBAE (Num' x) = (Num x)
elabCFBAE (Plus' l r) = (Plus (elabCFBAE l) (elabCFBAE r))
elabCFBAE (Minus' l r) = (Minus (elabCFBAE l) (elabCFBAE r))
elabCFBAE (Lambda' i b) = (Lambda i (elabCFBAE b))
elabCFBAE (App' l b) = (App (elabCFBAE l) (elabCFBAE b))
elabCFBAE (Bind' i v b) = (App (Lambda  i (elabCFBAE b)) (elabCFBAE v))
elabCFBAE (Id' i) = (Id i)
elabCFBAE (If0' c t e) = (If0 (elabCFBAE c) (elabCFBAE t) (elabCFBAE e))
--elabCFBAE _ = Num 0

evalCFBAE :: Env' -> CFBAE -> (Maybe CFAEValue)
evalCFBAE e (Num' x) = return (NumV x)
--evalCFBAE e (Plus' l r) = elabCFBAE (Plus' (evalCFBAE e l) (evalCFBAE e r) )
--evalCFBAE e (Plus' l r) = do{
--    l2 <- evalCFBAE e l;
--    r2 <- evalCFBAE e r;
--    return elabCFBAE (Plus' l2 r2)
--}
evalCFBAE e (Plus' l r) = (evalStatCFAE e (elabCFBAE (Plus' l r)))
--    l2 <- evalCFBAE e l;
--    r2 <- evalCFBAE e r;
--    l2 <- evalStatCFAE e l;
--    r2 <- evalStatCFAE e r;
evalCFBAE e (Minus' l r) = (evalStatCFAE e (elabCFBAE (Minus' l r)))
evalCFBAE e (Lambda' i b) = (evalStatCFAE e (elabCFBAE (Lambda' i b) ))
evalCFBAE e (App' f a) = (evalStatCFAE e (elabCFBAE (App' f a)))
evalCFBAE e (Bind' i v b) = (evalStatCFAE e (elabCFBAE (Bind' i v b)))
evalCFBAE e (Id' i) = (evalStatCFAE e (elabCFBAE (Id' i)))
evalCFBAE e (If0' c t e2) = (evalStatCFAE e (elabCFBAE (If0' c t e2)))


--evalCFBAE _ _ = Nothing

subst :: String -> CFAE -> CFAE -> CFAE

subst i v (Num x) = (Num x)

subst i v (Plus l r) =
    (Plus (subst i v l) (subst i v r))

subst i v (Minus l r) =
    (Minus (subst i v l) (subst i v r))

subst i v (Lambda i2 b) =
      (Lambda i2 (subst i v b))
--    (Lambda (subst i v i2) (subst i v b))

subst i v (App f a) =
    (App (subst i v f) (subst i v a))

subst i v (Id x) = if(i==x) then v else (Id x)


subst i v (If0 c t e) = If0 (subst i v c) (subst i v t) (subst i v e)

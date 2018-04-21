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
evalDynCFAE _ _ = Nothing

data CFAEValue where
  NumV :: Int -> CFAEValue
  ClosureV :: String -> CFAE -> Env -> CFAEValue
  deriving (Show,Eq)

type Env' = [(String,CFAEValue)]

evalStatCFAE :: Env' -> CFAE -> (Maybe CFAEValue)
evalStatCFAE _ _ = Nothing

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

elabCFBAE :: CFBAE -> (Maybe CFAE)
elabCFBAE _ = Nothing

evalCFBAE :: Env -> CFBAE -> (Maybe CFAEValue)
evalCFBAE _ _ = Nothing

{-# LANGUAGE GADTs,FlexibleContexts #-}

-- Problem Author: Perry Alexander
-- Solution Author: Austin Bailey 2550099 a604b997@ku.edu

-- Note: To run the HUnit tests, load file in GHCI (via ':load p0.hs') and type 'runTestTT tests'
import Test.HUnit

-- Imports for Monads

import Control.Monad

-- BBAE AST and Type Definitions

data TBBAE where
  TNum :: TBBAE
  TBool :: TBBAE
  deriving (Show,Eq)

data BBAE where
  Num :: Int -> BBAE
  Plus :: BBAE -> BBAE -> BBAE
  Minus :: BBAE -> BBAE -> BBAE
  Bind :: String -> BBAE -> BBAE -> BBAE
  Id :: String -> BBAE
  Boolean :: Bool -> BBAE
  And :: BBAE -> BBAE -> BBAE
  Leq :: BBAE -> BBAE -> BBAE
  IsZero :: BBAE -> BBAE
  If :: BBAE -> BBAE -> BBAE -> BBAE
  deriving (Show,Eq)

type Env = [(String,BBAE)]

type Cont = [(String,TBBAE)]

evalS :: BBAE -> (Maybe BBAE)
evalS (Num a) = return (Num a)
evalS (Boolean b) = return (Boolean b)
evalS (Plus l r) = do{
    (Num l) <- evalS l;
    (Num r) <- evalS r;
    return (Num (l+r))
}
evalS (Minus l r) = do{
    (Num l) <- evalS l;
    (Num r) <- evalS r;
    return (Num (l-r))
}
evalS (And l r) = do{
    (Boolean l) <- evalS l;
    (Boolean r) <- evalS r;
    return (Boolean (l&&r))
}
evalS (Leq l r) = do{
    (Num l) <- evalS l;
    (Num r) <- evalS r;
    if(l<=r)
        then return (Boolean True)
        else return (Boolean False)
}
evalS (Bind i v b)=do{
    v' <- evalS v;
    evalS (subst i v' b)
}
evalS (Id x) = Nothing--dont evaluate outside of Bind
evalS (IsZero x) = do{
    (Num x) <- evalS x;
    if(x==0)
        then return (Boolean True)
        else return (Boolean False)
}
evalS (If c t e)= do{
    (Boolean c) <- evalS c;
    if(c)
        then return t;
        else return e;
}

evalM :: Env -> BBAE -> (Maybe BBAE)

evalM e (Num x) = return (Num x)
evalM e (Boolean x) = return (Boolean x)
evalM e (Plus l r) = do{
    (Num l2) <- evalM e l;
    (Num r2) <- evalM e r;
    return (Num (l2+r2))
}
evalM e (Minus l r) = do{
    (Num l2) <-evalM e l;
    (Num r2) <-evalM e r;
    return (Num (l2-r2))
}
evalM e (And l r) = do{
    (Boolean l2) <- evalM e l;
    (Boolean r2) <- evalM e r;
    return (Boolean (l2&&r2))
}
evalM e (Leq l r) = do{
    (Num l2) <- evalM e l;
    (Num r2) <- evalM e r;
    if (l2<=r2)
        then return (Boolean True)
        else return (Boolean False)
}
--evalM e (Bind i v b) = (evalM ((i , (evalM e v)):e) b)
evalM e (Bind i v b) = do{
    v' <- evalM e v;
    evalM ((i, v'):e) b
}
evalM e (Id n) = (lookup n e)
evalM e (IsZero x) = do{
    (Num x2) <- evalM e x;
    if(x2==0)
        then return (Boolean True)
        else return (Boolean False)
}
evalM e (If c t e2) = do{
    (Boolean c) <- evalM e c;
    if(c == True)
        then return t;
        else return e2;
}

testBBAE :: BBAE -> Bool

--testBBAE (Num x) = do{
--    resultS <- evalS(Num x);
--    resultM <- evalM [] (Num x);
--    (resultS == resultM)
--}
testBBAE (Num x) = (evalS (Num x) == evalM [] (Num x))
testBBAE (Boolean b) = (evalS (Boolean b) == evalM [] (Boolean b))
testBBAE _ = True

typeofM :: Cont -> BBAE -> (Maybe TBBAE)

typeofM c (Num x) = (Just (TNum));
typeofM c (Boolean b) = (Just (TBool));
typeofM c (Plus l r) = do{
    tl <- typeofM c l;
    tr <- typeofM c r;
    if(tl == TNum && tr == TNum)
        then return TNum;
        else Nothing;
}
typeofM c (Minus l r) = do{
    tl <- typeofM c l;
    tr <- typeofM c r;
    if(tl == TNum && tr == TNum)
        then return TNum;
        else Nothing;
}
typeofM c (And l r) = do{
    tl <- typeofM c l;
    tr <- typeofM c r;
    if(tl == TBool && tr == TBool)
        then return TBool;
        else Nothing;
}
typeofM c (Leq l r) = do{
    tl <- typeofM c l;
    tr <- typeofM c r;
    if(tl == TNum && tr == TNum)
        then return TBool;
        else Nothing;
}
typeofM c (Bind i v b) = do{
    tv <- typeofM c v;
    typeofM ((i, tv):c) b;
}
typeofM c (Id x) = do{
    lookup x c;
}
typeofM c (IsZero x) = do{
    tx <- typeofM c x;
    if(tx == TNum)
        then return TBool;
        else Nothing;
}
typeofM c (If cond t e) = do{
    tcond <- typeofM c cond;
    tt <- typeofM c t;
    te <- typeofM c e;
    if(tcond==TBool && tt == te)
        then return tt;
        else Nothing;
}

evalT :: BBAE -> (Maybe BBAE)
evalT e = do{
    typeofM [] e;
    evalM [] e;
}


--varid, value, term, result
subst :: String -> BBAE -> BBAE -> BBAE

subst i v (Num x) = (Num x)

subst i v (Boolean x) = (Boolean x)

--subst i v (Plus l r) = do{
--    l' <- subst i v l;
--    r' <- subst i v r;
--    Plus (l' r')
--}

subst i v (Plus l r) =
    (Plus (subst i v l) (subst i v r))

subst i v (Minus l r) =
    (Minus (subst i v l) (subst i v r))

subst i v (And l r) =
    (And (subst i v l) (subst i v r))

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

--testing

test1 = TestCase (assertEqual "subst Num test 1 (1)"  (subst "a" (Num 3) (Num 4)) (Num 4))
test2 = TestCase (assertEqual "subst Boolean test 1 (2)" (subst "a" (Boolean False) (Boolean True)) (Boolean True))
--test3 = TestCase (assertEqual "subst Plus test 1" (subst "a" (Num 3)))
--test3 = TestCase (assertEqual "Subst ID test 1" (subst "m" (Num 3) (Plus (Id "m") (Num 2))) (Num 5))
test3 = TestCase (assertEqual "Subst Id test 1 (3)" (subst "m" (Num 5) (Id "m")) (Num 5))
test4 = TestCase (assertEqual "Subst Plus test 1 (4)" (subst "m" (Num 2) (Plus (Id "m") (Num 3)) ) (Plus (Num 2) (Num 3)) )
test5 = TestCase (assertEqual "Subst Minus test 1 (5)" (subst "x" (Num 4) (Minus (Num 3) (Id "x"))) (Minus (Num 3) (Num 4)))
test6 = TestCase (assertEqual "Subst And test 1 (6)" (subst "y" (Boolean True) (And (Id "y") (Id "y"))) (And (Boolean True) (Boolean True)))
test7 = TestCase (assertEqual "Subst Leq test 1 (7)" (subst "y" (Boolean False) (Leq (Id "y") (Id "y"))) (Leq (Boolean False) (Boolean False)))
test8 = TestCase (assertEqual "Subst Bind test 1 (8)" (subst "i" (Num 2) (Bind "i" (Num 3) (Id "i"))) (Bind "i" (Num 3) (Id "i")))
test9 = TestCase (assertEqual "Subst Bind test 2 (9)" (subst "i" (Num 2) (Bind "j" (Id "i") (Id "i"))) (Bind "j" (Num 2) (Num 2)))
test10 = TestCase (assertEqual "Subst iszero test 1 (10)" (subst "i" (Num 2) (IsZero (Id "i"))) (IsZero( Num 2)))
test11 = TestCase (assertEqual "EvalS Num Test 1 (11)" (evalS (Num 123)) (Just(Num 123)))
test12 = TestCase (assertEqual "EvalS Boolean Test 1 (12)" (evalS (Boolean True)) (Just(Boolean True)))
--test12 = TestCase (assertEqual "EvalS Boolean Test 1 (12)" (evalS (Boolean False)) (Boolean False))
test13 = TestCase (assertEqual "EvalS Plus Test 1 (13)" (evalS (Plus (Num 3) (Num 4))) (Just(Num 7)))
test14 = TestCase (assertEqual "EvalS Minus Test 2 (14)" (evalS (Minus (Num 5) (Num 2))) (Just(Num 3)))
test15 = TestCase (assertEqual "EvalS And Test 1 (15)" (evalS (And (Boolean True) (Boolean False))) (Just(Boolean False)))
test16 = TestCase (assertEqual "EvalS Leq Test 1 (16)" (evalS (Leq (Num 3) (Num 3))) (Just(Boolean True)))
test17 = TestCase (assertEqual "EvalS Bind Test 1 (17)" (evalS (Bind "x" (Num 9) (Plus (Id "x") (Id "x")))) (Just(Num 18)))
test18 = TestCase (assertEqual "EvalS Id test 1 (18)" (evalS (Id "x")) Nothing)
test19 = TestCase (assertEqual "Evals IsZero test 1(19)" (evalS (IsZero (Num 0))) (Just(Boolean True)))
test20 = TestCase (assertEqual "EvalS If Test 1(20)" (evalS (If (Boolean True) (Num 5) (Num 6))) (Just(Num 5)))
test21 = TestCase (assertEqual "EvalM Num (21)"      (evalM [] (Num 123))  (Just(Num 123)) )
test22 = TestCase (assertEqual "EvalM Num2(22)"      (evalM [("x",(Num 123))] (Num 12))  (Just(Num 12)))
test23 = TestCase (assertEqual "EvalM Boolean (23)"  (evalM [("x",(Num 211))] (Boolean True))    (Just(Boolean True))  )
test24 = TestCase (assertEqual "EvalM Plus (24)"     (evalM [("yx",(Num 123))] (Plus (Num 12) (Num 32)))   (Just(Num 44))  )
test25 = TestCase (assertEqual "EvalM Minus (25)"    (evalM [("blah",(Num 1))] (Minus (Num 321) (Num 111)))  (Just(Num 210))  )
test26 = TestCase (assertEqual "EvalM And (26)"      (evalM [("x",(Num 0))] (And (Boolean True) (Boolean True)))  (Just(Boolean True)) )
test27 = TestCase (assertEqual "EvalM Leq (27)"      (evalM [("x",(Num 0))] (Leq (Num 5) (Num 5)))    (Just(Boolean True)) )
test28 = TestCase (assertEqual "EvalM Bind (28)"     (evalM [("x",(Num 0))] (Bind ("y") (Num 5) (Plus (Id "y")  (Id "y") ) ) )   (Just(Num 10))  )
test29 = TestCase (assertEqual "EvalM Bind (29)"     (evalM [("x",(Num 1))] (Bind ("y") (Num 5) (Plus (Id "y")  (Id "x") ) ) )   (Just(Num 6))  )
test30 = TestCase (assertEqual "EvalM Id (30)"       (evalM [("x",(Num 1))] (Id "y"))    (Nothing) )
test31 = TestCase (assertEqual "EvalM Id (31)"       (evalM [("x",(Num 3))] (Id "x"))  (Just(Num 3)) )
test32 = TestCase (assertEqual "EvalM IsZero (32)"   (evalM [("x",(Num 3))] (IsZero (Num 5)))    (Just(Boolean False)) )
test33 = TestCase (assertEqual "EvalM If (33)"       (evalM [("x",(Num 3))] (If (Boolean True) (Num 4) (Num 5)))  (Just(Num 4)))
test34 = TestCase (assertEqual "TypeofM Num"         (typeofM [] (Num 5))  (Just TNum))
test35 = TestCase (assertEqual "TypeofM Boolean"     (typeofM [] (Boolean True))   (Just TBool))
test36 = TestCase (assertEqual "TypeOfM Plus"        (typeofM [("x",TNum)] (Plus (Num 4) (Num 5)))  (Just TNum)  )
test37 = TestCase (assertEqual "TypeOfM Minus"       (typeofM [("x",TNum)] (Minus (Num 4) (Num 3))) (Just TNum))
test38 = TestCase (assertEqual "TypeOfM And"         (typeofM [("x",TBool)] (And (Boolean False) (Boolean True))) (Just TBool))
test39 = TestCase (assertEqual "TypeOfM Leq"         (typeofM [("x",TNum)] (Leq (Num 4) (Num 2354)))  (Just TBool) )
test40 = TestCase (assertEqual "TypeOfM Bind"        (typeofM [] (Bind ("y") (Num 5) (Plus (Id "y") (Id "y"))  ) )  (Just TNum) )
test41 = TestCase (assertEqual "TypeOfM Id"          (typeofM [] (Id "y")) (Nothing) )
test42 = TestCase (assertEqual "TypeofM Id2"         (typeofM [("x",TNum)]   (Id "x")) (Just TNum))
test43 = TestCase (assertEqual "TypeofM Id3"         (typeofM [("x",TNum),("x",TBool)] (Id "x")) (Just TNum) )
tests = TestList [
  TestLabel "SubstNumTest1(1)" test1,
  TestLabel "SubstBoolTest1(2)" test2,
  TestLabel "SubstIDTest1(3)" test3,
  TestLabel "SubstPlusTest1(4)" test4,
  TestLabel "SubstMinusTest1(5)" test5,
  TestLabel "SubstAndTest1(6)" test6,
  TestLabel "SubstLeqTest1(7)" test7,
  TestLabel "SubstBindTest1(8)" test8,
  TestLabel "SubstBindTest2(9)" test9,
  TestLabel "SubstIsZeroTest1(10)" test10,
  TestLabel "EvalSNumTest1(11)" test11,
  TestLabel "EvalSBooleanTest1(12)" test12,
  TestLabel "EvalSPlusTest1(13)" test13,
  TestLabel "EvalSMinusTest1(14)" test14,
  TestLabel "EvalSAndTest1(15)" test15,
  TestLabel "EvalSLeqTest1(16)" test16,
  TestLabel "EvalSBindTest1(17)" test17,
  TestLabel "EvalSIdTest1(18)" test18,
  TestLabel "EvalSIsZero1(19)" test19,
  TestLabel "EvalSIf1(20)" test20,
  TestLabel "EvalMNum(21)" test21,
  TestLabel "EvalMNum(22)" test22,
  TestLabel "EvalMBoolean(23)" test23,
  TestLabel "EvalMPlus(24)" test24,
  TestLabel "EvalMMinus(25)" test25,
  TestLabel "EvalMAnd(26)" test26,
  TestLabel "EvalMLeq(27)" test27,
  TestLabel "EvalMBind(28)" test28,
  TestLabel "EvalMBind2(29)" test29,
  TestLabel "EvalMID(30)" test30,
  TestLabel "EvalMID2(31)" test31,
  TestLabel "EvalMIsZero(32)" test32,
  TestLabel "EvalMIf(33)" test33,
  TestLabel "TypeofMNUM(34)" test34,
  TestLabel "TypeOfMBoolean(35)" test35,
  TestLabel "Typeofmplus(36)" test36,
  TestLabel "TypeOfMMinus(37)" test37,
  TestLabel "TypeOfMAnd(38)" test38,
  TestLabel "TypeOfMLeq(39)" test39,
  TestLabel "TypeOFMBind(40)" test40,
  TestLabel "TyoeofMID1(41)" test41,
  TestLabel "TypeofMID2(42)" test42,
  TestLabel "TypeofMID3(43)" test43
  ]

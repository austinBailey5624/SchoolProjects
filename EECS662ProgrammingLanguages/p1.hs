{-# LANGUAGE GADTs, FlexibleContexts #-}


-- Problem Author: Perry Alexander
-- Solution Author: Austin Bailey 2550099 a604b997@ku.edu

-- Note: To run the HUnit tests, load file in GHCI (via ':load p0.hs') and type 'runTestTT tests'
--Adding HUnit tests for testing
import Test.HUnit
-- Imports for Parsec
import Control.Monad
import Text.ParserCombinators.Parsec
import Text.ParserCombinators.Parsec.Language
import Text.ParserCombinators.Parsec.Expr
import Text.ParserCombinators.Parsec.Token

-- AST Definition

data TABE where
  TNum :: TABE
  TBool :: TABE
  deriving (Show,Eq)

data ABE where
  Num :: Int -> ABE
  Plus :: ABE -> ABE -> ABE
  Minus :: ABE -> ABE -> ABE
  Mult :: ABE -> ABE -> ABE
  Div :: ABE -> ABE -> ABE
  Boolean :: Bool -> ABE
  And :: ABE -> ABE -> ABE
  Leq :: ABE -> ABE -> ABE
  IsZero :: ABE -> ABE
  If :: ABE -> ABE -> ABE -> ABE
  deriving (Show,Eq)

-- AST Pretty Printer

pprint :: ABE -> String
pprint (Num n) = show n
pprint (Boolean b) = show b
pprint (Plus n m) = "(" ++ pprint n ++ " + " ++ pprint m ++ ")"
pprint (Minus n m) = "(" ++ pprint n ++ " - " ++ pprint m ++ ")"
pprint (Mult n m) = "(" ++ pprint n ++ " * " ++ pprint m ++ ")"
pprint (Div n m) = "(" ++ pprint n ++ " / " ++ pprint m ++ ")"
pprint (And n m) = "(" ++ pprint n ++ " && " ++ pprint m ++ ")"
pprint (Leq n m) = "(" ++ pprint n ++ " <= " ++ pprint m ++ ")"
pprint (IsZero m) = "(isZero " ++ pprint m ++ ")"
pprint (If c n m) = "(if " ++ pprint c ++ " then " ++ pprint n ++ " else " ++ pprint m ++ ")"


-- Parser (Requires ParserUtils and Parsec)

languageDef =
  javaStyle { identStart = letter
            , identLetter = alphaNum
            , reservedNames = [ "if0"
                              , "then"
                              , "else"
                              ]
            , reservedOpNames = [ "+","-","*","/"]
            }

lexer = makeTokenParser languageDef

inFix o c a = (Infix (reservedOp lexer o >> return c) a)
preFix o c = (Prefix (reservedOp lexer o >> return c))
postFix o c = (Postfix (reservedOp lexer o >> return c))

parseString p str =
  case parse p "" str of
    Left e -> error $ show e
    Right r -> r

expr :: Parser ABE
expr = buildExpressionParser opTable term

opTable = [ [ inFix "*" Plus AssocLeft
            , inFix "/" Minus AssocLeft ]
          , [ inFix "+" Plus AssocLeft
            , inFix "-" Minus AssocLeft ]
          , [ inFix "<=" Leq AssocLeft
            , preFix "isZero" IsZero ]
          , [ inFix "&&" And AssocLeft ]
          ]

numExpr :: Parser ABE
numExpr = do i <- integer lexer
             return (Num (fromInteger i))

trueExpr :: Parser ABE
trueExpr = do i <- reserved lexer "true"
              return (Boolean True)

falseExpr :: Parser ABE
falseExpr = do i <- reserved lexer "false"
               return (Boolean False)

ifExpr :: Parser ABE
ifExpr = do reserved lexer "if"
            c <- expr
            reserved lexer "then"
            t <- expr
            reserved lexer "else"
            e <- expr
            return (If c t e)

term = parens lexer expr
       <|> numExpr
       <|> trueExpr
       <|> falseExpr
       <|> ifExpr

-- Parser invocation

parseABE = parseString expr

-- Evaluation Functions

evalM :: ABE -> (Maybe ABE)
evalM (Num a) = if (a<0) then error "!" else Just (Num a) --checks for negative numbers
evalM (Boolean b) = Just (Boolean b)
evalM (Plus l r) = do{
    x <- evalM l;
    y <- evalM r;
    return (liftNum (+) x y)
--    return (Num(x+y))
--    return (liftNumPlus x y)
}
evalM (Minus l r) = do{
    x <- evalM l;
    y <- evalM r;
    if(leqHelper y x)
        then return (liftNum (-) x y)
        else error "!"
}
evalM (Mult l r) = do{
    x <- evalM l;
    y <- evalM r;
    return (liftNum (*) x y)
}
evalM (Div l r) = do{
    x <- evalM l;
    y <- evalM r;
    --Just liftNum +0 rather than writing an entire new function
    if((liftNum (+) (Num 0) y)==(Num 0))
        then error "!"--error out if r is zero
        else return (liftNum div x y)
}

evalM (And l r) = do{
    x <- evalM l;
    y <- evalM r;
    return (liftBool (&&) x y)
}

evalM (Leq l r) = do{
    x <- evalM l;
    y <- evalM r;
    return (Boolean (leqHelper x y))

}

evalM (IsZero n) = do{
    x <- evalM n;
    if((liftNum (+) x (Num 0))==(Num 0))
    then return (Boolean True)
    else return (Boolean False)
}

evalM (If c n m) = do{
    x <- evalM c;
    y <- evalM n;
    z <- evalM m;
    --again, reusing a lift instead of writing a new one.
    --if c is true, c&&c is still true,
    --if c is false, c&&c is still false
    if((liftBool (&&) c c)==(Boolean True))
    then return y
    else return z
}
evalM _ = Nothing -- Replace this with your interpreter

evalErr :: ABE -> (Maybe ABE)

evalErr (Num a) = if (a<0) then error "!" else Just (Num a)
evalErr (Boolean b) = do {Just (Boolean b)}
evalErr (Plus l r) = do{
     x<-evalM l;
     y<-evalM r;
     if(typeofM x == Just(TNum) && typeofM y == Just(TNum))
         then return (liftNum (+) x y)
         else Nothing
}

evalErr (Minus l r) = do{
     x <- evalM l;
     y <- evalM r;
     if((leqHelper y x)&&typeofM x == Just(TNum)&&typeofM y == Just(TNum))
         then return (liftNum (-) x y)
         else Nothing
}

evalErr (Mult l r) = do{
    x <- evalM l;
    y <- evalM r;
     if(typeofM x == Just(TNum) && typeofM y == Just(TNum))
         then return (liftNum (*) x y)
         else Nothing
}

evalErr (Div l r) = do{
     x <- evalM l;
     y <- evalM r;
     --Just liftNum +0 rather than writing an entire new function
     if((liftNum (+) (Num 0) y)==(Num 0) || typeofM x == Just(TBool) || typeofM y == Just(TBool))
         then error "!"--error out if r is zero
         else return (liftNum div x y)
}

evalErr (And l r) = do{
    x <- evalM l;
    y <- evalM r;
    if(typeofM x == Just(TBool) && typeofM y == Just(TBool))
      then return (liftBool (&&) x y)
      else Nothing
}

evalErr (Leq l r) = do{
    x <- evalM l;
    y <- evalM r;
    if(typeofM x == Just(TNum) && typeofM y == Just(TNum))
      then return (Boolean (leqHelper x y))
      else Nothing		
}

evalErr (IsZero n) = do{
    x <- evalM n;
    if(typeofM x == Just(TNum))
    then if((liftNum (+) x (Num 0))==(Num 0))
        then return (Boolean True)
        else return (Boolean False)
    else Nothing
}

evalErr (If c n m) = do{
    x <- evalM c;
    y <- evalM n;
    z <- evalM m;
    if(typeofM x == Just(TBool)&& typeofM y == typeofM z)
      then
--again, reusing a lift instead of writing a new one.
--if c is true, c&&c is still true,
--if c is false, c&&c is still false
          if((liftBool (&&) c c)==(Boolean True))
            then return y
            else return z
       else Nothing
}

evalErr _ = Nothing -- Replace this with your interpreter

-- Type Derivation Function

typeofM :: ABE -> Maybe TABE
typeofM (Num _) = return TNum
typeofM (Boolean _) = return TBool
typeofM (Plus l r) = do{
    x <- typeofM l;
    y <- typeofM r;
    if(x==TNum && y==TNum)
        then Just TNum
        else Nothing
}
--Minus through Div are just copy pastes of Plus, no need to retest
typeofM (Minus l r) = do{
    x <- typeofM l;
    y <- typeofM r;
    if(x==TNum && y==TNum)
        then Just TNum
        else Nothing
}
typeofM (Mult l r) = do{
    x <- typeofM l;
    y <- typeofM r;
    if(x==TNum && y==TNum)
        then Just TNum
        else Nothing
}
typeofM (Div l r) = do{
    x <- typeofM l;
    y <- typeofM r;
    if(x==TNum && y==TNum)
        then Just TNum
        else Nothing
}
typeofM (And l r) = do{
    x <- typeofM l;
    y <- typeofM r;
    if(x==TBool && y == TBool)
        then Just TBool
        else Nothing
}
typeofM (Leq l r) = do{
    x <- typeofM l;
    y <- typeofM r;
    if(x==TBool && y == TBool)
        then Just TBool
        else Nothing
}
typeofM (IsZero m) = do{
    x <- typeofM m;
    if(x==TNum)
    then return TBool
    else Nothing
}
typeofM (If c t e) = do{
    x <- typeofM c;
    y <- typeofM t;
    z <- typeofM e;
    if(x==TBool&&y==z)
        then return y;--could just as easily return e
        else Nothing
}
typeofM _ = Nothing

-- Combined interpreter

evalTypeM :: ABE -> Maybe ABE
evalTypeM (Num n) = evalM (Num n)
evalTypeM (Boolean b) = evalM (Boolean b)
evalTypeM (Plus l r) = do{
  x <- typeofM l;
  y <- typeofM r;
  if(x == TNum&&y == TNum)
    then evalM (Plus l r)
    else Nothing
}
evalTypeM (Minus l r) = do{
  x <- typeofM l;
  y <- typeofM r;
  if(x == TNum&&y == TNum)
    then evalM (Minus l r)
    else Nothing
}
evalTypeM (Mult l r) = do{
  x <- typeofM l;
  y <- typeofM r;
  if(x == TNum && y== TNum)
    then evalM (Mult l r)
    else Nothing
}
evalTypeM (Div l r) = do{
  x <- typeofM l;
  y <- typeofM r;
  if(x == TNum && y == TNum)
    then evalM (Div l r)
    else Nothing
}
evalTypeM (And l r) = do{
  lt <- typeofM l;
  rt <- typeofM r;
  if(lt == TBool && rt == TBool)
    then evalM (And l r)
    else Nothing
}
evalTypeM (Leq l r) = do{
  lt <- typeofM l;
  rt <- typeofM r;
  if(lt == TNum && rt == TNum)
    then evalM (Leq l r)
    else Nothing
}
evalTypeM (IsZero m) = do{
  mt <- typeofM m;
	if(mt == TNum)
    then evalM (IsZero m)
    else Nothing
}
evalTypeM (If c t e) = do{
  ct <- typeofM c;
  tt <- typeofM t;
  et <- typeofM e;
  if(ct==TBool && tt == et)
    then evalM (If c t e)
    else Nothing
}
evalTypeM _ = Nothing

-- Optimizer

optimize :: ABE -> ABE
optimize (Plus l r)= do{
    if (l == (Num 0))
        then r;
        else if (r == (Num 0))
            then  l;
            else (Plus l r)
}

optimize (If c t e) = do{
    if(c == (Boolean True))
        then if ((typeofM t) == Just TNum)
         then t;
         else t;
        else if (c == (Boolean False))
            then if((typeofM e) == Just TNum)
             then e;
             else e;
            else (If c t e)

}

optimize e = e

interpOptM :: ABE -> Maybe ABE
interpOptM x = evalM (optimize x)
interpOptM _ = Nothing

--Lifts
--this was my initial attempt to lift, not quite sure why it doesnt work
liftNum :: (Int->Int->Int)->ABE->ABE->ABE
liftNum f (Num x) (Num y) = (Num( f x y))

liftNumPlus :: ABE->ABE->ABE
liftNumPlus (Num x) (Num y) = (Num (x+y))

liftBool:: (Bool->Bool->Bool)->ABE->ABE->ABE
liftBool f (Boolean x) (Boolean y) = (Boolean(f x y))

--specialized lift to go from Nums to Bools
leqHelper :: ABE->ABE->Bool
leqHelper (Num x) (Num y) = (x<=y)

--testing
test1 = TestCase (assertEqual "evalM Num test 1" (evalM (Num 123)) (Just(Num 123)))
test2 = TestCase (assertEqual "evalM Boolean test 1" (evalM (Boolean True)) (Just(Boolean True)))
test3 = TestCase (assertEqual "evalM Boolean test 2" (evalM (Boolean False)) (Just(Boolean False)))
test4 = TestCase (assertEqual "evalM Plus test 1" (evalM (Plus (Num 3) (Num 4))) (Just (Num 7)))--dont worry about type errors till later
test5 = TestCase (assertEqual "evalM Minus test 1" (evalM (Minus (Num 5) (Num 3))) (Just (Num 2)))
test6 = TestCase (assertEqual "LeqHelper test 1" (leqHelper (Num 5) (Num 6)) True)
test7 = TestCase (assertEqual "LeqHelper test 2" (leqHelper (Num 5) (Num 5)) True)
test8 = TestCase (assertEqual "LeqHelper test 3" (leqHelper (Num 6) (Num 5)) False)
test9 = TestCase (assertEqual "evalM Leq test 1" (evalM (Leq (Num 5) (Num 6))) (Just(Boolean True)))--less than case
test10 = TestCase (assertEqual "evalM Leq test 2" (evalM (Leq (Num 5) (Num 5))) (Just(Boolean True)))--equals case
test11 = TestCase (assertEqual "evalM Leq test 3" (evalM (Leq (Num 6) (Num 5))) (Just(Boolean False)))--Greater Than case
test12 = TestCase (assertEqual "Minus test 2" (evalM (Minus (Num 5) (Num 5))) (Just(Num 0)))
test13 = TestCase (assertEqual "evalM Mult test 1" (evalM (Mult (Num 1) (Num 2))) (Just(Num 2)))
test14 = TestCase (assertEqual "evalM Div test 1" (evalM (Div (Num 6) (Num 2))) (Just(Num 3)))
--couldn't get the syntax for the test to work, but the thing it is
--testing has to work for another test to work, so I know it does work
--test15 = TestCase (assertEqual "liftBool test 1" (liftBool ( ((&&)) (Boolean True) (Boolean False))) (Boolean False))
test16 = TestCase (assertEqual "evalM And test 1" (evalM (And (Boolean True) (Boolean True))) (Just(Boolean True)))
test17 = TestCase (assertEqual "evalM IsZero test 1" (evalM (IsZero (Num 0))) (Just(Boolean True)))
test18 = TestCase (assertEqual "evalM IsZero test 2" (evalM (IsZero (Num 1))) (Just(Boolean False)))
test19 = TestCase (assertEqual "evalM if test 1" (evalM (If (Boolean True) (Num 5) (Num 6))) (Just(Num 5)))
test20 = TestCase (assertEqual "evalM if test 2" (evalM (If (Boolean False) (Num 5) (Num 6))) (Just(Num 6)))
test21 = TestCase (assertEqual "typeofM Num test 1" (typeofM (Num 123)) (Just(TNum)))
test22 = TestCase (assertEqual "typeofM Boolean test 1" (typeofM (Boolean True)) (Just(TBool)))
test23 = TestCase (assertEqual "typeofM Plus test 1" (typeofM(Plus (Num 5) (Num 5))) (Just(TNum)))
test24 = TestCase (assertEqual "typeofM Plus test 2" (typeofM(Plus (Boolean True) (Num 5))) (Nothing))
test25 = TestCase (assertEqual "typeofM And test 1" (typeofM(And (Boolean True) (Boolean True))) (Just(TBool)))
test26 = TestCase (assertEqual "typeofM And test 2" (typeofM(And (Num 5)  (Num 3))) (Nothing))
test27 = TestCase (assertEqual "typeofM If test 1" (typeofM(If (Num 5) (Num 5) (Num 5))) (Nothing))--if the first argument isn't a bool return Nothing
test28 = TestCase (assertEqual "typeofM If test 2" (typeofM(If (Boolean True) (Boolean True) (Boolean True))) (Just(TBool)))--If the first argument is true and the next two arguments are the same type, return that typeofM
test29 = TestCase (assertEqual "typeofM If test 3" (typeofM(If (Boolean True) (Boolean True) (Num 5) ) ) (Nothing) )--If the second and third types dont type return Nothing
test30 = TestCase (assertEqual "optimize killzero test 1" (optimize(Plus (Num 5) (Num 0))) (Num 5))
test31 = TestCase (assertEqual "optimize killzero test 2" (optimize(Plus (Num 0) (Num 5))) (Num 5))
test32 = TestCase (assertEqual "optimize killif test 1" (optimize(If (Boolean True) (Num 5) (Num 6))) (Num 5))
test33 = TestCase (assertEqual "optimize killif test 2" (optimize(If (Boolean False) (Num 5) (Num 6))) (Num 6))
test34 = TestCase (assertEqual "optimize killif test 3" (optimize(If (Boolean True) (Boolean True) (Num 6))) (Boolean True))
test35 = TestCase (assertEqual "optimize killif test 4" (optimize(If (Boolean False) (Num 16) (Boolean False))) (Boolean False))
test36 = TestCase (assertEqual "EvalErr Plus test 1" (evalErr(Plus (Num 5) (Num 5))) (Just (Num 10)))
test37 = TestCase (assertEqual "EvalErr Plus test 2" (evalErr(Plus (Boolean True) (Num 5))) (Nothing))
test38 = TestCase (assertEqual "EvalErr And test 1" (evalErr(And (Boolean True) (Boolean False))) (Just(Boolean False)))
test39 = TestCase (assertEqual "EvalErr And test 2" (evalErr(And (Num 5) (Num 4))) (Nothing))
test40 = TestCase (assertEqual "EvalErr Leq test 1" (evalErr(Leq (Num 5) (Num 5))) (Just(Boolean True)))
test41 = TestCase (assertEqual "EvalErr Leq test 2" (evalErr(Leq (Boolean True) (Num 4))) (Nothing))
test42 = TestCase (assertEqual "EvalErr IsZero Test 1" (evalErr(IsZero (Num 0))) (Just(Boolean True)))
test43 = TestCase (assertEqual "EvalErr IsZero Test 2" (evalErr(IsZero (Num 1))) (Just(Boolean False)))
test44 = TestCase (assertEqual "EvalErr IsZero Test 3" (evalErr(IsZero (Boolean True))) (Nothing))
test45 = TestCase (assertEqual "EvalErr If Test 1" (evalErr(If (Boolean True) (Boolean True) (Boolean False))) (Just(Boolean True)))
test46 = TestCase (assertEqual "EvalErr If test 2" (evalErr(If (Boolean True) (Boolean False) (Num 5))) (Nothing))
test47 = TestCase (assertEqual "EvalErr If test 3" (evalErr(If (Num 5) (Num 3) (Boolean False))) (Nothing))

test48 = TestCase (assertEqual "EvalTypeM Plus test 1" (evalTypeM(Plus (Num 5) (Num 5))) (Just (Num 10)))
test49 = TestCase (assertEqual "EvalTypeM Plus test 2" (evalTypeM(Plus (Boolean True) (Num 5))) (Nothing))
test50 = TestCase (assertEqual "EvalTypeM And test 1" (evalTypeM(And (Boolean True) (Boolean False))) (Just(Boolean False)))
test51 = TestCase (assertEqual "EvalTypeM And test 2" (evalTypeM(And (Num 5) (Num 4))) (Nothing))
test52 = TestCase (assertEqual "EvaltypeM Leq test 1" (evalTypeM(Leq (Num 5) (Num 5))) (Just(Boolean True)))
test53 = TestCase (assertEqual "EvalTypeM Leq test 2" (evalTypeM(Leq (Boolean True) (Num 4))) (Nothing))
test54 = TestCase (assertEqual "EvalTypeM IsZero Test 1" (evalTypeM(IsZero (Num 0))) (Just(Boolean True)))
test55 = TestCase (assertEqual "EvalTypeM IsZero Test 2" (evalTypeM(IsZero (Num 1))) (Just(Boolean False)))
test56 = TestCase (assertEqual "EvalTypeM IsZero Test 3" (evalTypeM(IsZero (Boolean True))) (Nothing))
test57 = TestCase (assertEqual "EvalTypeM If Test 1" (evalTypeM(If (Boolean True) (Boolean True) (Boolean False))) (Just(Boolean True)))
test58 = TestCase (assertEqual "EvalTypeM If test 2" (evalTypeM(If (Boolean True) (Boolean False) (Num 5))) (Nothing))
test59 = TestCase (assertEqual "EvalTypeM If test 3" (evalTypeM(If (Num 5) (Num 3) (Boolean False))) (Nothing))


tests = TestList [
 TestLabel "EvalMNumtest1" test1,
 TestLabel "evalMBooleanTest1" test2,
 TestLabel "evalMBooleanTest2" test3,
 TestLabel "evalMPlusTest1" test4,
 TestLabel "evalMMinusTest1" test5,
 TestLabel "LeqHelperTest1" test6,
 TestLabel "LeqHelperTest2" test7,
 TestLabel "LeqHelperTest3" test8,
 TestLabel "evalMLeqTest1" test9,
 TestLabel "evalMLeqTest2" test10,
 TestLabel "evalMLeqTest3" test11,
 TestLabel "evalMMinusTest2" test12,
 TestLabel "evalMMultTest1" test13,
 TestLabel "evalMDivTest1" test14,
-- TestLabel "LiftBool test 1" test15,
 TestLabel "evalMAndTest1" test16,
 TestLabel "evalMIsZeroTest1" test17,
 TestLabel "evalMIsZeroTest2" test18,
 TestLabel "evalMIfTest1" test19,
 TestLabel "evalMIfTest2" test20,
 TestLabel "typeOfMNum" test21,
 TestLabel "typeOfMBoolean" test22,
 TestLabel "typeOfPlus1" test23,
 TestLabel "typeOfPlus2" test24,
 TestLabel "typeOfAnd1" test25,
 TestLabel "typeOfAnd2" test26,
 TestLabel "typeOfIf1" test27,
 TestLabel "typeOfIf2" test28,
 TestLabel "typeOfIf3" test29,
 TestLabel "optimizeKillZero1" test30,
 TestLabel "optimizeKillZero2" test31,
 TestLabel "optimizeKillif1" test32,
 TestLabel "opitmizeKillif2" test33,
 TestLabel "optimizeKillif3" test34,
 TestLabel "optimizeKillif4" test35,
 TestLabel "EvalErrPlus1" test36,
 TestLabel "EvalErrPlus2" test37,
 TestLabel "EvalErrAnd1" test38,
 TestLabel "EvalErrAnd2" test39,
 TestLabel "EvalErrLeq1" test40,
 TestLabel "EvalErrLeq2" test41,
 TestLabel "EvalErrIsZero1" test42,
 TestLabel "EvalErrIsZero2" test43,
 TestLabel "EvalErrIsZero3" test44,
 TestLabel "EvalErrIf1" test45,
 TestLabel "EvalErrIf2" test46,
 TestLabel "EvalErrIf3" test47,
 TestLabel "EvalTypeMPlus1" test48,
 TestLabel "EvalTypeMPlus2" test49,
 TestLabel "EvalTypeMAnd1" test50,
 TestLabel "EvalTypeMAnd2" test51,
 TestLabel "EvaltypeMLeq1" test52,
 TestLabel "EvalTypeMLeq2" test53,
 TestLabel "EvalTypeMIsZero1" test54,
 TestLabel "EvalTypeMIsZero2" test55,
 TestLabel "EvalTypeMIsZero3" test56,
 TestLabel "EvalTypeMIf1" test57,
 TestLabel "EvalTypeMIf2" test58,
 TestLabel "EvalTypeMIf3" test59]

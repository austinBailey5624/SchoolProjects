{-# LANGUAGE GADTs, FlexibleContexts #-}

-- Problem Author: Perry Alexander
-- Solution Author: Austin Bailey 2550099 a604b997@ku.edu

-- Note: To run the HUnit tests, load file in GHCI (via ':load p0.hs') and type 'runTestTT tests'

-- Imports for QuickCheck
import System.Random
import Test.QuickCheck
import Test.QuickCheck.Gen
import Test.QuickCheck.Function
import Test.QuickCheck.Monadic

-- Imports for Parsec
import Control.Monad
import Text.ParserCombinators.Parsec
import Text.ParserCombinators.Parsec.Language
import Text.ParserCombinators.Parsec.Expr
import Text.ParserCombinators.Parsec.Token

--Adding HUnit tests for testing
import Test.HUnit
--
-- Simple caculator over naturals with no identifiers
--
-- Author: Perry Alexander
-- Date: Tue Jan 23 17:54:44 CST 2018
--
-- Source files for the Arithmetic Expressions (AE) language from PLIH
--

-- AST Definition

data AE where
  Num :: Int -> AE
  Plus :: AE -> AE -> AE
  Minus :: AE -> AE -> AE
  Mult :: AE -> AE -> AE
  Div :: AE -> AE -> AE
  If0 :: AE -> AE -> AE -> AE
  deriving (Show,Eq)

-- AE Parser (Requires ParserUtils and Parsec included above)

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

expr :: Parser AE
expr = buildExpressionParser operators term

operators = [
  [ inFix "*" Mult AssocLeft
    , inFix "/" Div AssocLeft ]
  , [ inFix "+" Plus AssocLeft
  , inFix "-" Minus AssocLeft ]
  ]

numExpr :: Parser AE
numExpr = do i <- integer lexer
             return (Num (fromInteger i))

ifExpr :: Parser AE
ifExpr  = do reserved lexer "if0"
             c <- expr
             reserved lexer "then"
             t <- expr
             reserved lexer "else"
             e <- expr
             return (If0 c t e)


term = parens lexer expr
       <|> numExpr
       <|> ifExpr

-- Parser invocation
-- Call parseAE to parse a string into the AE data structure.

parseAE = parseString expr

-- Evaluation Functions
-- Replace the bodies of these functions with your implementations for
-- Exercises 1-4.  Feel free to add utility functions or testing functions as
-- you see fit, but do not change the function signatures.  Note that only
-- Exercise 4 requires you to integrate the parser above.

evalAE :: AE -> Int
evalAE (Num a)     = if (a<0) then error "!" else a
evalAE (Plus l r)  = ((evalAE l) + (evalAE r))
evalAE (Minus l r) = if((evalAE l) - (evalAE r)<0) then error "!" else ((evalAE l)-(evalAE r))
evalAE (Mult l r)  = ((evalAE l) * (evalAE r))
evalAE (Div l r)   = if((evalAE r)==0) then error "!" else (evalAE l `div` evalAE r)
--note: c:conditional t:then e:else
evalAE (If0 c t e) = if((evalAE c)==0) then (evalAE t) else (evalAE e)
evalAE _ = 0

evalAEMaybe :: AE -> Maybe Int
evalAEMaybe (Num a)       = if(a<0) then error "!" else (Just a)
evalAEMaybe (Plus l r)    = case evalAEMaybe l of
                                Just x -> case evalAEMaybe r of
                                    Just y -> return (x + y)
                                    Nothing -> Nothing
                                Nothing -> Nothing
evalAEMaybe (Minus l r)   = case evalAEMaybe l of
                                Just x -> case evalAEMaybe r of
                                    Just y -> if(x-y < 0) then error "!" else return (x - y)
                                    Nothing -> Nothing
                                Nothing -> Nothing
--Note: didn't need to check that x*y is > 0 since both x and y have to be greater
--  than zero and a natural number times a natural number is always a natural number
evalAEMaybe (Mult l r)    = case evalAEMaybe l of
                                Just x -> case evalAEMaybe r of
                                    Just y -> return (x * y)
                                    Nothing -> Nothing
                                Nothing -> Nothing
evalAEMaybe (Div l r)     = if((evalAEMaybe r) == (Just 0)) then error "!"
                                else (case evalAEMaybe l of
                                    Just x -> case evalAEMaybe r of
                                        Just y -> return (x `div` y)
                                        Nothing ->Nothing
                                    Nothing -> Nothing)
evalAEMaybe (If0 c t e)   = case evalAEMaybe c of
                            Just 0 -> evalAEMaybe t
                            Just x -> evalAEMaybe e
                            _ -> Nothing
evalAEMaybe _ = Nothing

evalM :: AE -> Maybe Int
evalM (Num a)             = if(a<0) then error "!" else (Just a)
evalM (Plus l r)          = do {
                                x <- evalM l;
                                y <- evalM r;
                                return (x+y)
}
evalM (Minus l r)         = do {
                                x <- evalM l;
                                y <- evalM r;
                                if(x-y<0)
                                then Nothing
                                else return (x-y)
}
evalM (Mult l r)          = do {
                                x <- evalM l;
                                y <- evalM r;
                                return (x*y)
}
evalM (Div l r)           = do {
                                x <- evalM l;
                                y <- evalM r;
                                if(y==0)
                                then Nothing
                                else return (x `div` y)
}
evalM (If0 c t e)         = do {
                                x <- evalM c;
                                y <- evalM t;
                                z <- evalM e;
                                if(x==0)
                                then return y;
                                else return z;
}
evalM _ = Nothing

interpAE :: String -> Maybe Int

--interpAE str = evalM (ParseAE str) --this is my closest attempt for #4
interpAE _ = Nothing

test1 = TestCase (assertEqual "evalAE Num test 1" (evalAE (Num 123)) 123)

--Note, I couldn't get HUnit to check that conditions fail- heres my attempt
--test2 = TestCase (assertEqual  (evalAE (Num -123)) error "1")

test2 = TestCase (assertEqual "evalAE Plus test 1" (evalAE (Plus (Num 2) (Num 3))) 5)

test3 = TestCase (assertEqual "evalAE Minus test 1" (evalAE (Minus (Num 3) (Num 2))) 1)

test4 = TestCase (assertEqual "evalAE Mult test 1" (evalAE (Mult (Num 2) (Num 3))) 6)

test5 = TestCase (assertEqual "evalAE Div test 1" (evalAE (Div (Num 80) (Num 20))) 4)

test6 = TestCase (assertEqual "evalAE If0 test 1" (evalAE (If0 (Num 0) (Num 1) (Num 2))) 1)

test7 = TestCase (assertEqual "evalAE If0 test 2" (evalAE (If0 (Num 1) (Num 1) (Num 2))) 2)

test8 = TestCase (assertEqual "evalAEMaybe Num test 1" (evalAEMaybe(Num 5)) (Just 5))

test9 = TestCase (assertEqual "evalAEMaybe Plus test 1" (evalAEMaybe(Plus (Num 2) (Num 3))) (Just 5))

--tests that Nothing is returned when Nothing is left argument
--the below test cant be written since Plus takes an AE and Nothing is not an AE
--test10 = TestCase (assertEqual "evalAEMaybe Plus test 2" (evalAEMaybe(Plus (Nothing) (Num 2))) Nothing)

test10 = TestCase (assertEqual "evalAEMaybe Minus test 1" (evalAEMaybe(Minus (Num 5) (Num 3))) (Just 2))

test11 = TestCase (assertEqual "evalAEMaybe Mult test 1" (evalAEMaybe(Mult (Num 5) (Num 5))) (Just 25))

test12 = TestCase (assertEqual "evalAEMaybe Div test 1"  (evalAEMaybe(Div (Num 20) (Num 5))) (Just 4))

test13 = TestCase (assertEqual "evalAEMaybe If0 test 1" (evalAEMaybe(If0 (Num 0) (Num 1) (Num 2))) (Just 1))

test14 = TestCase (assertEqual "evalAEMaybe If0 test 2" (evalAEMaybe(If0 (Num 1) (Num 1) (Num 2))) (Just 2))

test15 = TestCase (assertEqual "evalM Num Test 1" (evalM(Num 13)) (Just 13))

test16 = TestCase (assertEqual "evalM Plus Test 1" (evalM(Plus (Num 123) (Num 234))) (Just 357))

test17 = TestCase (assertEqual "evalM Minus Test 1" (evalM(Minus (Num 789) (Num 345))) (Just 444))

test18 = TestCase (assertEqual "evalM Mult Test 1" (evalM(Mult (Num 5) (Num 5))) (Just 25))

test19 = TestCase (assertEqual "evalM Div Test 1" (evalM(Div (Num 32) (Num 4))) (Just 8))

test20 = TestCase (assertEqual "evalM If0 Test 1" (evalM(If0 (Num 0) (Num 3) (Num 4))) (Just 3))

test21 = TestCase (assertEqual "evalM If0 Test 2" (evalM(If0 (Num 1) (Num 3) (Num 4))) (Just 4))
tests = TestList [TestLabel "evalAENumtest1" test1,
 TestLabel "evalAEPlusTest1" test2,
 TestLabel "evalAEMinusTest1" test3,
 TestLabel "evalAEMultTest1" test4,
 TestLabel "evalAEDivTest1" test5,
 TestLabel "evalAEIf0Test1" test6,
 TestLabel "evalAEIf0Test2" test7,
 TestLabel "evalAEMaybeNumTest1" test8,
 TestLabel "evalAEMaybePlusTest1" test9,
 TestLabel "evalAEMaybeMinusTest1" test10,
 TestLabel "evalAEMaybeMultTest1" test11,
 TestLabel "evalAEMaybeDivTest1" test12,
 TestLabel "evalAEMaybeIf0Test1" test13,
 TestLabel "evalAEMaybeIf0Test2" test14,
 TestLabel "evalMNumTest1" test15,
 TestLabel "evalMPlusTest1" test16,
 TestLabel "evalMMinusTest1" test17,
 TestLabel "evalMMultTest1" test18,
 TestLabel "evalMDivTest1" test19,
 TestLabel "evalMIf0Test1" test20,
 TestLabel "evalMIf0Test2" test21]

--test2 = TestCase (assertEqual "evalAE If0 test 2" (evalAE (If0 (Num 1) (Num 1) (Num 2))) 2)


--tests = TestList [TestLabel "evalAEIf0test1" test1, TestLabel "evalAEIf0test2" test2]

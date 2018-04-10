{-------------------------------------------------------------------------------

LAB 1

-------------------------------------------------------------------------------}

import Prelude hiding (reverse)

{-------------------------------------------------------------------------------

Part 1: Numbers and digits

-------------------------------------------------------------------------------}

-- Write a function which returns the last digit of its input number.  For
-- example, `lastDigit 89` should return `9`.
lastDigit :: Int -> Int
lastDigit a =
  a `mod` 10

-- Write a function which returns its input number, but missing its last digit.
-- For example, `lastDigit 289` should return `28`.
allButLastDigit :: Int -> Int
allButLastDigit a =
   --truncate (a / 10)
   --a / 10
   quot a 10

-- Write a function which returns the digits of its input.  For example, `digits
-- 289` should return `[2,8,9]`
digits :: Int -> [Int]
digits a
  | (a < 1) = []
  | otherwise = digits (allButLastDigit a) ++ [lastDigit a]

-- Write a function which reverses its input list.  For example, `reverse
-- [2,8,9]` should return `[9,8,2]`.
reverse :: [Int] -> [Int]
reverse [] = []
reverse (x:xs) = reverse (xs) ++ [x]

-- Write a function which returns true if its input number is a palindrome.  A
-- palindrome is something which is the same backwards and forwards.  In this
-- case, you should have `palindrome 2442` returning `True`, but `palindrome 24`
-- returning `False`.
palindrome :: Int -> Bool
palindrome n =
  (digits n) == (reverse(digits n))


-- Write a function which reverses the input digits of its argument.  For
-- example, `reverseDigits 289` should return `982`.
reverseDigits :: Int -> Int
reverseDigits n = concatInts (digits n)

--helper function for reverseDigits
concatInts :: [Int] -> Int
concatInts [] = 0
concatInts (x:xs) = x + 10 * concatInts(xs)
{-------------------------------------------------------------------------------

Part 2: Sequences of numbers

-------------------------------------------------------------------------------}

-- Write a function which returns the n'th triangular numbers.  The n'th
-- triangular number is defined as the sum of 1 + 2 + ... + n.
tri :: Int -> Int
tri n
   |(n==0) = 0
   |(n==1) = 1
   |otherwise = n + tri (n-1)

-- Write a function which returns the n'th Fibonacci number (counting from 0).
-- The n'th Fibonacci number is defined as:
--   0                        if n is 0
--   1                        if n is 1
--   fib (n-1) + fib (n-2)    if n > 1
-- Challenge: do this in time linear in n.
fib :: Int -> Int
fib n
  |(n==0) = 0
  |(n==1) = 1
  |otherwise = fib (n-1) + fib (n-2)

-- Write a term which evaluates to an infinite list of 1s.
ones :: [Int]
ones = 1 : ones

-- Write a term which evaluates to the natural numbers.  Challenge: use zipWith
-- and ones.
nats :: [Int]
nats = 0 : zipWith (+) ones nats

-- Write a term which evaluates to the sequence of triangular numbers.
-- Challenge: use zipWith, not your tri function.
tris :: [Int]
tris = 0 : zipWith (+) (tail nats) tris

-- Write a term which evaluates to the sequence of Fibonacci numbers.
-- Challenge: use zipWith, not your fib function.  If you didn't get the linear
-- version of fib earlier, does this help?
fibs :: [Int]
fibs = [0,1] ++ zipWith (+) fibs (tail fibs)

module Hw0 where

{-------------------------------------------------------------------------------

HOMEWORK 0: Haskell review

DUE: Friday, September 1, 8:00 AM

This homework will allow you to review and demonstrate your familiarity with
Haskell.  You will be asked to write a number of small Haskell functions,
ranging from the simple to the not-as-simple.  Each function you are asked to
write will also come with two test cases; for full credit, you must provide at
least two more test cases.  (You may provide more than two if you find it
helpful when writing your solutions.)  The tests are written using HUnit, so you
will have to load ghci with -package HUnit.  Please consider filling out the
short survey at the end of the assignment; however, you do not have to fill it
out to receive full credit.

Note: To enable the test package, add -package HUnit
-------------------------------------------------------------------------------}

import Data.Char (toLower)
import Test.HUnit
import Data.List

{-------------------------------------------------------------------------------

PROBLEM 1: CIRCLES

This problem asks you to write some simple functions about circles on a plane.
We will represent a point as a pair of double-precision floating point numbers,
and a circle as a pair of the center (a point) and the radius (a Double).

  a) The function pointInCircle, given a circle and a point, should return True
  if the point is in the circle, and False otherwise.  Return True if the point
  is on the boundary of the circle.

  b) The function circleIntersectsCircle, given two circles, should return True
  if the circles intersect, and False otherwise.  Return True if the circles are
  tangent.

You will most likely need the standard Prelude function

  sqrt :: Double -> Double

which computes square roots; I have provided a similar function

  sqr :: Double -> Double

which computes squares.  Recall that the equation of a circle with center (x0,
y0) and radius r is

  sqrt (sqr (x - x0) + sqr (y - y0)) = r

-------------------------------------------------------------------------------}

type Point = (Double, Double)
type Circle = (Point, Double)

sqr x = x * x

pointInCircleTests =
    TestList [ "inside unit circle"      ~: pointInCircle ((0, 0), 1) (0.5, 0)     ~?= True
             , "outside unit circle"     ~: pointInCircle ((0, 0), 1) (1, 1)       ~?= False
             , "on unit circle"          ~: pointInCircle ((0, 0), 1) (0, 1)       ~?= True
             , "unit circle center"      ~: pointInCircle ((0, 0), 1) (0, 0)       ~?= True
             , "outside unit circle2"    ~: pointInCircle ((0, 0), 1) (0.75,0.75)    ~?= False
             , "inside circle"           ~: pointInCircle ((1, 2), 3) (0,0)        ~?= True
             , "outside circle"          ~: pointInCircle ((1, 2), 3) (4,4)        ~?= False
             ]

pointInCircle :: Circle -> Point -> Bool
pointInCircle c1 p1 =
  let xp = fst p1
      xc = fst (fst c1)
      yp = snd p1
      yc = snd (fst c1)
      r  = snd c1 in
  sqrt( sqr( abs( xp-xc ) ) + sqr( abs( yp-yc ) ) ) <= r

circleIntersectsCircleTests =
    TestList [ "unit circles touch"         ~: circleIntersectsCircle ((0, 0), 1) ((sqrt 2, sqrt 2), 1) ~?= True
             , "unit circles miss"          ~: circleIntersectsCircle ((0, 0), 1) ((2, 2), 1) ~?= False
             , "circle inside circle"       ~: circleIntersectsCircle ((0,0),5) ((1,1),1) ~?= True
             , "circles overlap"            ~: circleIntersectsCircle ((-1,0),1.2) ((1,0),1.2) ~?= True
             , "duplicate circles"          ~: circleIntersectsCircle ((0,0),1) ((0,0),1) ~?=True
             , "nonUnit circles miss"       ~: circleIntersectsCircle ((-1,0),0.9) ((1,0),0.9) ~?= False
             ]

circleIntersectsCircle :: Circle -> Circle -> Bool
circleIntersectsCircle c1 c2 =
  let r1 = snd c1 --radius of the first circle
      r2 = snd c2 --radius of the second circle
      xc1 = fst (fst c1) --x corrdinate of the center of the first circle
      xc2 = fst (fst c2) --x corrdinate of the center of the second circle
      yc1 = snd (fst c1) --y corrdinate of the center of the first circle
      yc2 = snd (fst c2) in--y corrdinate of the center of the first circle
  sqrt( sqr(xc1 - xc2) + sqr(yc1 - yc2)) <= r1 + r2


{-------------------------------------------------------------------------------

PROBLEM 2: RECURSION

This problem asks you to write a series of simple recursive functions operating
on numbers and lists.  Do NOT use the standard Prelude functions map, filter,
foldl, foldr, sum, or list comprehensions.

  a) The function upTo, given an input integer n, should return a list of the
  integers from 0 to n (inclusive).  You may assume that n >= 0.

  b) The function downFrom, given an input integer n, should return a list of
  the integers from n to 0 (inclusive).  You may assume that n >= 0.

  c) The function sumSquares, given a list of integers, should return the sum of
  the squares of those integers.  For example, sumSquares [3, 4, 5] should
  return 50.

  d) The function sumSquaredEvens, given a list of integers, should return the
  sum of the squares of the even integers in its input list.  For example,
  sumSquaredEvens [3, 4, 5] should return 16.

  e) The function isSorted, given a list of integers, should return True if the
  list is sorted in ascending order, and False otherwise.  For example, isSorted
  [2,3,3,4] should return True, and isSorted [3,2,3,4] should return False.

  f) The function secondLargest, given a list of integers, should return the
  second largest value in the list.  For example: secondLargest [3,6,5] should
  return 5.  You may assume that the input list will contain at least 2
  elements.  If all list values are equal, you should return that value;
  however, otherwise, multiple occurrences of the same value should not be
  counted multiple times.  For example, secondLargest [6,5,6] should still
  return 5, not 6.

-------------------------------------------------------------------------------}

upToTests =
    TestList [ "up to 4" ~: upTo 4 ~?= [0,1,2,3,4]
             , "up to 2" ~: upTo 2 ~?= [0,1,2]
             , "up to 0" ~: upTo 0 ~?= [0]
             , "up to 1" ~: upTo 1 ~?= [0,1]
             ]

upTo :: Int -> [Int]
--upTo n = [0..n]
upTo n =
  if n >= 1 then upTo (n-1) ++ [n] else [n]


downFromTests =
    TestList [ "down from 4" ~: downFrom 4 ~?= [4,3,2,1,0]
             , "down from 2" ~: downFrom 2 ~?= [2,1,0]
             , "down from 0" ~: downFrom 0 ~?= [0]
             , "down from 1" ~: downFrom 1 ~?= [1,0]
             ]

downFrom :: Int -> [Int]
--downFrom n = [n..0]
downFrom n =
  if (n >= 1) then [n] ++ downFrom (n-1) else [n]

sumSquaresTests =
    TestList [ "squares of [1,2,3]" ~: sumSquares [1,2,3] ~?= 14
             , "squares of [2,3,4]" ~: sumSquares [2,3,4] ~?= 29
             , "squares of [1,3,5]" ~: sumSquares [1,3,5] ~?= 35
             , "squares of [2,4,6]" ~: sumSquares [2,4,6] ~?= 56
             ]

sumSquares :: [Int] -> Int
sumSquares [] = 0
sumSquares (x:xs) = x*x + sumSquares xs

sumSquaredEvensTests =
    TestList [ "squares of evens from [1,2,3]" ~: sumSquaredEvens [1,2,3] ~?= 4
             , "squares of evens from [2,3,4]" ~: sumSquaredEvens [2,3,4] ~?= 20
             , "squares of evens from [1,3,5]" ~: sumSquaredEvens [1,3,5] ~?= 0
             , "squares of evens from [2,4,6]" ~: sumSquaredEvens [2,4,6] ~?= 56
             ]

sumSquaredEvens :: [Int] -> Int
sumSquaredEvens [] = 0
sumSquaredEvens (x:xs) =
  if (x `mod` 2 == 0) then x*x + (sumSquaredEvens xs) else sumSquaredEvens xs

isSortedTests =
    TestList [ "[1,2,3] is sorted"      ~: isSorted [1,2,3] ~?= True
             , "[3,2,1] is not sorted"  ~: isSorted [3,2,1] ~?= False
             , "[1,1,1] is sorted"      ~: isSorted [1,1,1] ~?= True
             , "[1,2,2] is sorted"      ~: isSorted [1,2,2] ~?= True
             ]

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted (x:xs)=
  if(xs == []) then True else if(x <= (head xs)) then isSorted(xs) else False

secondLargestTests =
    TestList [ "second largest of [4,2,5,1]" ~: secondLargest [4,2,5,1] ~?= 4
             , "second largest of [5,6,6]"   ~: secondLargest [5,6,6]   ~?= 5
             , "second largest of [1,2,3]"   ~: secondLargest [1,2,3]   ~?= 2
             , "second largest of [1,1,2,2]" ~: secondLargest [1,1,2,2] ~?= 1
             ]

-- The following three lines were taken from https://smthngsmwhr.wordpress.com/2012/11/09/sorting-algorithms-in-haskell/
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = quicksort [y | y <- xs, y <= x] ++ [x] ++ quicksort [y | y <- xs, y > x]
--

secondLargest :: [Int] -> Int
secondLargest (x:xs) = head (tail (reverse(quicksort(nub(x:xs)))))

{-------------------------------------------------------------------------------

PROBLEM 3: LISTS WITHOUT RECURSION

This problem asks you to rewrite several of the problems from the previous
problem, but now WITHOUT using recursion.  You will most likely need the
standard Prelude functions map, filter, and foldl or foldr.  Do NOT use the
standard Prelude sum function or list comprehensions.

  a) sumSquares' should behave identically to sumSquares

  b) sumSquaredEvens' should behave identically to sumSquaredEvens

The following are more challenging, and require non-trivial folds.  Think: what
is true at each step of the recursion? what information from each step do I need
in the next?

  c) isSorted' should behave identically to isSorted

  d) secondLargest' should behave identically to secondLargest

-------------------------------------------------------------------------------}

sumSquares'Tests =
    TestList [ "squares (again) of [1,2,3]" ~: sumSquares' [1,2,3] ~?= 14
             , "squares (again) of [2,3,4]" ~: sumSquares' [2,3,4] ~?= 29
             , "squares (again) of [1,3,5]" ~: sumSquares' [1,3,5] ~?= 35
             , "squares (again) of [2,4,6]" ~: sumSquares' [2,4,6] ~?= 56
             ]

sumSquares' :: [Int] -> Int
sumSquares' (x:xs) = foldr (\x y -> (x*x) +y) 0 (x:xs)

sumSquaredEvens'Tests =
    TestList [ "squares (again) of evens from [1,2,3]" ~: sumSquaredEvens' [1,2,3] ~?= 4
             , "squares (again) of evens from [2,3,4]" ~: sumSquaredEvens' [2,3,4] ~?= 20
             , "squares (again) of evens from [1,3,5]" ~: sumSquaredEvens' [1,3,5] ~?= 0
             , "squares (again) of evens from [2,4,6]" ~: sumSquaredEvens' [2,4,6] ~?=56
             ]

sumSquaredEvens' :: [Int] -> Int
sumSquaredEvens' (x:xs) = foldr (\x y -> (x*x) +y) 0 (filter even (x:xs))

isSorted'Tests =
    TestList [ "[1,2,3] is sorted (again)" ~: isSorted' [1,2,3] ~?= True
             , "[3,2,1] is not sorted (again)" ~: isSorted' [3,2,1] ~?= False
             -- Your tests go here
             ]

isSorted' :: [Int] -> Bool
isSorted' (x:xs) = error "not defined"

secondLargest'Tests =
    TestList [ "second largest (again) of [4,2,5,1]" ~: secondLargest' [4,2,5,1] ~?= 4
             , "second largest (again) of [5,6,6]"   ~: secondLargest' [5,6,6] ~?= 5
             , "second largest of [1,2,3]"           ~: secondLargest' [1,2,3]   ~?= 2
             , "second largest of [1,1,2,2]"         ~: secondLargest' [1,1,2,2] ~?= 1
             ]

secondLargest' :: [Int] -> Int
secondLargest' (x:xs) = head (tail (reverse(quicksort(nub(x:xs)))))

{-------------------------------------------------------------------------------

PROBLEM 4: BLACKJACK

Blackjack, or 21, is one of the oldest known gambling games.  In its simplest
form, it is played between a single player and a dealer.  The player and dealer
each have a hand, scored as follows:

  - Face cards (King, Queen, and Jack) are each worth 10 points
  - Aces are worth EITHER 1 or 11 points
  - Other cards are worth their pip value (for example, a nine of spades is
    worth 9 points).

This problem asks you to write a function beats which, given the player's hand
and the dealer's hand (represented as lists of Cards), returns True if the
player has won, and False otherwise.  For our purposes, the player can win three
ways:

  - The player has 21 points from a two card hand, while the dealer does not.
    (This is called a "natural" 21).

  - The player's hand can be scored at or under 21 points, but the dealer's hand
    cannot be scored at or under 21 points

  - Both hands can be scored under 21 point, and the player's score is higher
    than the dealer's.

Note that the rules are tilted in favor of the dealer: if both hands are natural
21s, or both hands have the same score <= 21, or both hands are bust, the dealer
wins.

For more information on the game, see https://en.wikipedia.org/wiki/Blackjack

Because suit does not matter for (modern) scoring, we omit suits from our
representation of cards.

I have provided a function readHand, which transforms strings of characters into
lists of cards.  Aces through Tens are represented by the first letter of their
names, while other cards by their numeric value.  For example, readHand "at4"
will return [Ace, Rank 10, Rank 4].

-------------------------------------------------------------------------------}

data Card = Ace | King | Queen | Jack | Rank Int

-- Provided testing code

readHand :: String -> [Card]
readHand = map (readCard . toLower)
    where readCard 'a' = Ace
          readCard 'k' = King
          readCard 'q' = Queen
          readCard 'j' = Jack
          readCard 't' = Rank 10
          readCard c   = Rank (read [c])

blackjackTests =
    TestList [ "dealer bust" ~: readHand "aj9" `beats` readHand "kj9" ~?= True
             , "natural" ~: readHand "aj" `beats` readHand "92k" ~?= True
             -- Your tests go here
             ]

-- End testing code

--valueAcesOne :: [Card] -> Int
--valueAcesOne (c:cs)
--      |c == [] = 0
--      |c == Ace = 1 + valueAcesOne(cs)
--      |c == King = 10 + valueAcesOne(cs)
--      |c == Queen = 10 + valueAcesOne(cs)
--      |c == Jack = 10 + valueAcesOne(cs)
--      |otherwise = Rank + valueAcesOne(cs)

beats :: [Card] -> [Card] -> Bool
beats = error "not defined"

{-------------------------------------------------------------------------------

PROBLEM 5: DISJUNCTIVE NORMAL FORM

Disjunctive normal form (DNF) refers to a form of Boolean formulae in which no
disjunction (OR, which I will write \/) appears inside a conjunction (AND, which
I will write /\), and neither appears inside a negation (which I will write ~).
We are not concerned with quantifiers, and will assume that implications have
already be rewritten in terms of /\, \/, and ~.  For example, this formula is in
DNF:

   A \/ (B /\ C) \/ (B /\ ~D)

while this formula is not:

   A \/ (B /\ (C \/ D))

nor is this one:

   A \/ (B /\ ~(C /\ D))

Your task is to write a function dnf which transforms arbitrary input Boolean
formulae into Boolean formulae DNF.

Your implementation will need the following equations (A,B, and C are arbitrary
formulae)

  Distribution of /\ over \/:
    A /\ (B \/ C) == (A /\ B) \/ (A /\ C)
    (A \/ B) /\ C == (A /\ C) \/ (B /\ C)

  De Morgan's Laws:
    ~(A /\ B) == ~A \/ ~B
    ~(A \/ B) == ~A /\ ~B

  Double negation elimination:
    ~~A == A

For testing, I have provided a function isDnf, which returns True if its input
is in disjunctive normal form and False otherwise, and a function printFormula,
whose output is slightly easier to read than the derived Show instance.

-------------------------------------------------------------------------------}

data Formula = Atom String | Not Formula | Formula :/\: Formula | Formula :\/: Formula
  deriving Show

-- Provided testing code

printFormula phi = putStrLn (p 0 phi)
    where p _ (Atom s) = s
          p _ (Not x) = "~" ++ p 3 x
          p n (phi :\/: psi)
              | n == 0 || n == 1 = p 1 phi ++ " \\/ " ++ p 1 psi
              | otherwise = "(" ++ p 1 phi ++ " \\/ " ++ p 1 psi ++ ")"
          p n (phi :/\: psi)
              | n == 0 || n == 2 = p 2 phi ++ " /\\ " ++ p 1 psi
              | otherwise = "(" ++ p 2 phi ++ " /\\ " ++ p 2 psi ++ ")"

isDnf phi = isDnf' 0 phi
    where isDnf' _ (Atom x)       = True
          isDnf' _ (Not (Atom x)) = True
          isDnf' 0 (phi :\/: psi) = isDnf' 0 phi && isDnf' 0 psi
          isDnf' 0 (phi :/\: psi) = isDnf' 1 phi && isDnf' 1 psi
          isDnf' 1 (phi :/\: psi) = isDnf' 1 phi && isDnf' 1 psi
          isDnf' _ _              = False

dnfTests =
    TestList [ "double negation" ~: isDnf (dnf (Not (Not (Atom "x")))) ~?= True
             , "de Morgan's laws" ~: isDnf (dnf (Not (Atom "x" :\/: Atom "y"))) ~?= True
             -- Your tests go here
             ]

-- End testing code

dnf :: Formula -> Formula
dnf = error "dnf not defined"

{-------------------------------------------------------------------------------

TEST DRIVER

-------------------------------------------------------------------------------}

allTests =
    TestList [ pointInCircleTests, circleIntersectsCircleTests
             , upToTests, downFromTests, sumSquaresTests, sumSquaredEvensTests
             , isSortedTests, secondLargestTests
             , sumSquares'Tests, sumSquaredEvens'Tests, isSorted'Tests
             , secondLargest'Tests
             , blackjackTests
             , dnfTests
             ]

{-------------------------------------------------------------------------------

SURVEY

1) How did this assignment go for you?  How difficult did you find it?  Did you
have to refer to any references on Haskell?

It went poorly, I thought it was really hard, and I had a reference open in
another window constantly

2) Do you have any questions about the problems?

Yes, I asked them during office hours

3) How long did the assignment take?

~12 hrs

-------------------------------------------------------------------------------}

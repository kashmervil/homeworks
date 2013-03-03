import Data.List(elemIndex)
import Data.Maybe(fromJust)

IndexOfMaxSum ::(Num a,Ord a) => [a] -> Int
IndexOfMaxSum xs = fromJust (elemIndex (maximum neighbour) neighbour) + 1 
     where neighbour = zipWith (+) xs (tail xs) 
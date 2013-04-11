import Control.Monad
pairwiseProd :: Int -> [Int]
pairwiseProd n = [1..n] >>= \x -> [1..n] >>= (\y -> [x*y])

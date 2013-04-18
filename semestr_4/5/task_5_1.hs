import Control.Monad
import Data.List
helper :: Int -> [[Int]]
helper 0 = [[]]
helper n = [1..n] >>= (\x -> map (x:) (par (n - x)))

par :: Int -> [[Int]]
par x = nub $ map sort $ helper x

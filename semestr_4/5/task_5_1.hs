import Control.Monad

par 0 = [[]]
par n = [1..n] >>= (\x -> map (x:) (par (n - x)))

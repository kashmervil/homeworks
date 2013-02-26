twoExp :: (Num a) => Int -> [a]
twoExp n = zipWith (^) (replicate n 2) [1..n]

quantityOfOdd1 :: (Integral a) => [a] -> a
quantityOfOdd1 xs = sum (map (\ x -> mod x 2) xs)

quantityOfOdd2 :: (Integral a) => [a] -> Int
quantityOfOdd2 xs = length (filter odd xs)

quantityOfOdd3 :: (Integral a) => [a] -> Int
quantityOfOdd3 xs = foldr (\x acc -> if (odd x) then acc + 1 else acc) 0 xs
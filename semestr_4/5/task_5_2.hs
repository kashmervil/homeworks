allOf1 :: (Eq a) => (a -> Bool) -> [a] -> Bool
allOf1 p xs = all p xs

allOf2 :: (Eq a) => (a -> Bool) -> [a] -> Bool
allOf2 p xs = and $ map p xs

allOf3 :: (Eq a) => (a -> Bool) -> [a] -> Bool
allOf3 p xs = foldr (&&) True $ map p xs

allOf4 :: (Eq a) => (a -> Bool) -> [a] -> Bool
allOf4 p xs = length (filter p xs) == length xs

allOf5 :: (Eq a) => (a -> Bool) -> [a] -> Bool
allOf5 _ [] = True
allOf5 p (x:xs) = p x && allOf4 p xs


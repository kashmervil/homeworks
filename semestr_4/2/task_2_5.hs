polyndrom :: (Eq a) => [a] -> Bool
polyndrom xs = (==) xs (reverse xs)
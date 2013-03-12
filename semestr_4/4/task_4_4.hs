import Data.List (group)
unique :: (Eq a) => [a] -> Bool
unique x = length x == length (group x)
posit :: (Eq a) => a -> [a] -> Int
posit p xs = if (elem p xs)
                    then length $ takeWhile (/= p) xs
					else -1
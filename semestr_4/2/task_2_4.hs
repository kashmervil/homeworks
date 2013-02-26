find :: (Eq a1, Num a) => [a1] -> a1 -> a
find xs y = find' 0 xs y
    where find' :: (Eq a1, Num a) => a -> [a1] -> a1 -> a
          find' _ [] _ = -1
          find' pos (x:xs) y = if (y == x)
		                    then pos
        		            else find' (pos + 1) xs y
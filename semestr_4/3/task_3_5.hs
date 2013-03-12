data Tree a = Empty 
            | Node a (Tree a) (Tree a)
			deriving (Show)

minDist :: (Tree a)-> Integer
minDist Empty = 0
minDist (Node _ left right) = 1 + min (height left) (height right) 			
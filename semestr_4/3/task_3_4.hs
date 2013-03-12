data Tree a = Empty 
            | Node a (Tree a) (Tree a)
			deriving (Show)

height :: (Tree a)-> Integer
height Empty = 0
height (Node _ left right) = 1 + max (height left) (height right) 			
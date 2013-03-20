data Tree a = EmptyTree
            | Node a (Tree a) (Tree a)
			deriving (Show, Eq) 

foldt :: ( a -> b -> b) -> b -> Tree a -> b
foldt _ z EmptyTree = z
foldt f z (Node x left right) = foldt f (f x (foldt f z left)) right

neg ::(Ord a,Num a) => Tree a -> [a]
neg xs = filter (<0) $ foldt (:) [] xs
import Data.Maybe
data Tree a = EmptyTree
            | Node a (Tree a) (Tree a)
			deriving (Show, Eq) 
 
treeInsert :: (Ord a) => a -> Tree a -> Tree a  
treeInsert x EmptyTree = Node x EmptyTree EmptyTree 
treeInsert x (Node a left right)   
    | x == a = Node x left right  
    | x < a  = Node a (treeInsert x left) right  
    | x > a  = Node a left (treeInsert x right) 
data Result a = NotFound | Found [a] deriving (Show)
treeSearch _          EmptyTree          = Nothing
treeSearch predicate (Node x left right) = if predicate x  
	                                            then Just x
                                                else if leftSearch == Nothing then rightSearch else leftSearch
                                                where leftSearch = treeSearch predicate left
                                                      rightSearch = treeSearch predicate right														
    
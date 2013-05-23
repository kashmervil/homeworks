import Data.Maybe
import Data.List(delete,sortBy)

data Tree a   = EmptyTree
            | Node a (Tree a) (Tree a)
                        deriving (Show,Eq)

insert :: (Ord a, Num i) => a -> Tree (a,i) -> Tree (a,i)
insert x tree = insert' x tree 0

insert' :: (Ord a, Num i) => a -> Tree (a,i) -> i -> Tree (a,i)
insert' x EmptyTree c = Node (x,c) EmptyTree EmptyTree
insert' x (Node (a,l) left right) c
    | x == a = Node (x,c) left right
    | x < a  = Node (a,l) (insert' x left (c+1)) right
    | x > a  = Node (a,l) left (insert' x right (c+1))

remove :: (Ord a, Num i, Ord i) => a -> Tree (a,i) -> Tree (a,i)
remove d tree = fromList (delete d (map fst (sortBy (\ x y -> compare (snd x) (snd y)) (toList tree))))

toList :: Tree a -> [a]
toList tree = foldt (:) [] tree

fromList :: (Ord a, Num i) => [a] -> Tree (a,i) 
fromList xs = foldl (flip insert) EmptyTree xs

search _          EmptyTree          = Nothing
search predicate (Node (x,c) left right) = if predicate x
                                                    then Just x
                                                else if leftSearch == Nothing then rightSearch else leftSearch
                                                where leftSearch = search predicate left
                                                      rightSearch = search predicate right

foldt :: ( a -> b -> b) -> b -> Tree a -> b
foldt _ z EmptyTree = z
foldt f z (Node x left right) = foldt f (f x (foldt f z left)) right

height :: (Tree a) -> Integer
height EmptyTree = 0
height (Node _ left right) = 1 + max (height left) (height right)

size :: Tree a -> Integer
size tree = foldt (\_ y -> y + 1) 0 tree

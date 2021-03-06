import System.Random
data Tree a = EmptyTree
            | Node a (Tree a) (Tree a)
                        deriving (Show, Eq)

treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert x EmptyTree = Node x EmptyTree EmptyTree
treeInsert x (Node a left right)
    | x == a = Node x left right
    | x < a  = Node a (treeInsert x left) right
    | x > a  = Node a left (treeInsert x right)

foldt :: ( a -> b -> b) -> b -> Tree a -> b
foldt _ z EmptyTree = z
foldt f z (Node x left right) = foldt f (f x (foldt f z left)) right

treeMap :: (a -> b) -> Tree a -> Tree b
treeMap _ EmptyTree = EmptyTree
treeMap f (Node x left right) = Node (f x) (treeMap f left) (treeMap f right)

treeRand :: Tree Int -> Tree Int
treeRand = treeMap (fst .random . mkStdGen)

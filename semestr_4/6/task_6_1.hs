import Data.Maybe

data Tree  = EmptyTree
           | Node Char Tree Tree
              deriving (Show,Eq)
showt :: Tree -> String
showt EmptyTree  = "e"
showt (Node x left right) = 'n': x : (showt left ++ showt right)

readt :: String -> Maybe Tree
readt str = res >>= \x -> if (snd x /= "") then Nothing
                          else return (fst x)
    where res = readt' str
            where readt' :: String -> Maybe (Tree, String)
                  readt' ('e':cs) = return (EmptyTree, cs)
                  readt' ('n':c:cs) = readt' cs >>= (\x -> readt' (snd x) 
                                          >>= (\y -> return ( Node c (fst x) (fst y), snd y)))
                  readt' _         = Nothing

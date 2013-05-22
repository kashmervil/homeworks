import Control.Monad

big :: [Int] -> Maybe Int
big (x:y:z:xs) = return xs >>= \s -> if (x < y)&&(y > z) 
                                        then Just y 
                                        else big (y:z:s) 
big _          = Nothing
 

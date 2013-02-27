import Data.Char
sum' :: (Show s) => s -> Int
sum' n = sum [digitToInt x | x <- (show n)]
            	   
            	   
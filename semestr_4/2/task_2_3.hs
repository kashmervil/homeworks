sum' :: (Integral n, Show s) => s -> n
sum' n = sum [toInt x | x <- (show n)]
    where
        toInt :: Integral a => Char -> a
        toInt x = case x of 
                     '0'   ->  0
                     '1'   ->  1
                     '2'   ->  2
                     '3'   ->  3 
                     '4'   ->  4
                     '5'   ->  5
                     '6'   ->  6
                     '7'   ->  7
                     '8'   ->  8
                     '9'   ->  9 

            	   
            	   
data Fiction = Book {name :: String, author :: String, cost :: Int} 
             | Magazine {name :: String, year :: Int, issue :: Int, cost :: Int}
totalPrice :: [Fiction] -> Int
totalPrice xs = foldr (+) 0 $ map cost xs
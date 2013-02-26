fib :: (Integral a) => a -> a
fib 1 = 1
fib 2 = 1
fib x = fib (x - 1) + fib (x - 2)

main = do
   putStrLn "Number of element of Fibbonachi sequence = "
   x <- getLine
   putStr $ show $ fib (read x :: Integer)
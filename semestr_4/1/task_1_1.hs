fact :: (Integral n) => n -> n
fact 0 = 1
fact n = n * fact (n-1)

main = do
    putStr "Factorial of n = \n"
    n <- getLine
    putStrLn ("n! = " ++ (show $fact(read n :: Integer)))
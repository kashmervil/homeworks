type Polynomnom = [Int]


showp :: Polynomnom -> String
showp [] = "" 
showp xs = nom ++ showp (init xs)
    where nom 
            | x == 1 = temp
            | x == 0 = ""
            | x < 0  = "-" ++ show (abs x) ++ temp
            | otherwise = "+" ++ show (abs x) ++ temp
            where x = last xs
                  temp
                     | (x == 1)&&(l == 0) = "+1"
                     | (l == 0)&&(x /= 1) = ""
                     | otherwise           = "x^" ++ show l
                       where l = length xs - 1

arifm :: (Int -> Int -> Int) -> Polynomnom -> Polynomnom -> Polynomnom
arifm f p1 p2 = zipWith f (p1 ++ (take (-degsub) zeros)) (p2 ++ (take degsub zeros))  
    where degsub = length p1 - length p2  
          zeros = repeat 0

infixr 2 .+ 
(.+) :: Polynomnom -> Polynomnom -> Polynomnom
(.+) = arifm (+)

infixl 2 .-
(.-) :: Polynomnom -> Polynomnom -> Polynomnom
(.-) = arifm (-)
 
infixr 4 .*
(.*) :: Polynomnom -> Polynomnom -> Polynomnom
(.*) = helper 0
    where
        helper :: Int -> Polynomnom -> Polynomnom -> Polynomnom
        helper _ p1 [] = []
        helper c p1 (x:xs) = (zeros c ++ (map (*x) p1)) .+ (helper (c+1) p1 xs)
            where zeros x = take x $ repeat 0


polyndrom :: (Eq a) => [a] -> Bool

polyndrom [] = True
polyndrom [_] = True
polyndrom xs = ( head xs == last xs)&&(polyndrom $ init $ tail $ xs )
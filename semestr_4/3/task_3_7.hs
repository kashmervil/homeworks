--func f g l = filter f (map g l)
--func f g   = (filter f) . (map g)
--func f g   = (.) (filter f) (map g)
--func f     = ((.) (filter f)) . map
--func         = flip(.) map . (.) . filter 

func :: (b -> Bool) -> (a -> b) -> [a] -> [b]
func = flip(.) map . (.) . filter 

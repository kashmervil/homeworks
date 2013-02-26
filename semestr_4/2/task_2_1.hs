rev :: [a] -> [a]
rev tmp = rev' tmp []
    where
        rev' :: [a] -> [a] -> [a]
        rev' [] tmp = tmp
        rev' (x:xs) tmp = rev' xs (x:tmp)
					

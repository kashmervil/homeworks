bracketCheck :: String -> Bool
bracketCheck xs = (fst f == 0)&&(snd f)
    where f = foldl 
	                (\ (acc,result) x ->
                                    (if x == '(' 
									       then (acc + 1,result)
										   else (acc - 1,acc > 0))) (0,True) (filter (\ x -> elem x "()") xs)
--func x l = map (\y -> y * x) l   eta conversion in lambada (\y -> y * x) = (*) x
--func x l = map ((*) x) l         eta conversion in main function (reducing of argument l)
--func x = map (*) x               we can also reduce argument x
--func = map .(*)                  use the composition veiw

func :: (Integer a) => a -> [a] -> [a]
func = map.(*) --now it's totally free from points, you know


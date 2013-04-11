import Control.Applicative
import Data.List (group)
combin :: (Eq a) => Int -> [a] -> [[a]]
combin 1 xs = group xs
combin n xs = (:) <$> xs <*> combin (n-1) xs

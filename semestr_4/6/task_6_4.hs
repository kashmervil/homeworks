import Data.List
import Control.Monad
import Data.Maybe

data Graph = Graph [Int] [((Int, Int), Float)]
            deriving Show
data Path = Path Int Float Int
            deriving(Eq,Show)
instance Ord Path where
    compare (Path _ x _) (Path _ y _) = compare x y

dijkstra :: Int -> Graph -> [(Int,Float)]
dijkstra s (Graph vs es) = result (helper firstStep [])
    where result :: [Path] -> [(Int,Float)]
          result [] = []
          result ((Path i d pd):ps) = (i,d): result ps
          firstStep :: [Path]
          firstStep = map (\v -> (Path v (if v == s then 0 else 1/0) v)) vs
          helper :: [Path] -> [Path] -> [Path]
          helper [] vs = vs
          helper rest visited =
              let nearest = minimum rest
                  newVisited = nearest : visited
                  nRest = (map (\p -> min p (makePath nearest p)) . delete nearest) rest
                  makePath (Path nrstId nrDist _) (Path p _ _) = (Path p  ((rage nrstId p) + nrDist)  nrstId)
              in  helper nRest newVisited
          rage ver ver' = if (lookup (ver,ver') es) == Nothing then 1/0
                                                    else fromJust (lookup (ver,ver') es)
example :: Graph
example = Graph [1,2,3,4] [((1,2),4.0),((2,1),4.0),((1,3),2.0),((3,1),2.0),((1,4),0.5),((4,1),0.5),((3,4),1.0),((4,3),1.0),((2,3),1.0),((3,2),1.0)]

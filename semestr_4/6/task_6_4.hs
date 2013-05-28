import Data.List
import Control.Monad
import Data.Maybe

data Graph = Graph [Int] [((Int, Int), Int)]

type Path = (Int,Int,Int)

instance Ord Path where
    compare (_,x,_) (_,y,_) = compare x y

dijkstra :: Int -> Graph -> [Path]
dijkstra s (Graph vs es) = helper firstStep
    where firstStep :: [Path]
          firstStep = map (\v -> (v,(if v == s then 0 else 1/0),v)) []
          helper :: [Path] -> [Path] -> [Path]
          helper [] vs = vs
          helper rest visited =
              let nearest = minimum rest
                  newVisited = nearest : visited
                  nRest = (map (\p -> min p (makePath nearest p)) . delete nearest) rest
                  makePath (nrstId, nrDist,_) (pId,_,_) = (pId, ((rage nrstId pId) + nrDist), nrstId)
              in  helper nRest newVisited
          rage ver ver' = if (lookup (ver,ver') es) == Nothing then 1/0
                                                    else fromJust (lookup (ver,ver') es)


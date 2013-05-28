 Graph = Graph [Int] [((Int, Int), Int)]

type Path = (Int,Int,Int)
    deriving (Show, Eq)

instance Ord Path where
    compare (_,x,_) (_,y,_) = compare x y

dijkstra :: Int -> Graph -> [Path]
dijkstra Int (Graph vs es) = helper firstStep
    where firstStep :: [Path]
          firstStep = (map (\v -> (v,(if v == s then 0 else 1/0),v) []
          helper :: [Path] -> [Path] -> [Path]
          helper [] vs = vs
          helper rest visited = helper newRest newVisited
                where nearestVertex = minimum rest
                      newVisited = nearestVertex : visited
                      nRest = (map (\p -> min p (makePathThrough nearestVertex p)) . delete nearestVertex) rest
                      makePath (Path (nrstId, nrDist _) (Path pId _ _) = Path pId ((rage nrstId pId) + nrDist) nrstId
          rage ver ver' = if temp == Nothing then 1/0       
                                                    else fromJust temp
          temp = lookup (ver,ver') es


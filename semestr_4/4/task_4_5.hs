import Data.List
import System.IO
listing :: [Int] -> IO ()	
listing xs = do
              putStr ("choose command of \n '0' - exit \n '1' - insert \n '2' - delete \n '3' - print \n")
              key <- getLine
              case key of "0" -> return ()
                          "1" -> do   
                                    putStr ("insert - ")
                                    value <- readLn
                                    listing (insert value xs)
                          "2" -> do
                                    putStrLn ("delete - ")
                                    value <- readLn
                                    listing (delete value xs)
                          "3" -> do
                                    putStr (show xs)
                                    listing xs
                          otherwise -> listing xs
main = do
    listing []
import System.IO
import Control.Monad

find_max_element [x]    = x 
find_max_element (x:xs) = if x < max_rest then max_rest else x  where max_rest = find_max_element xs 
  
find_index (x:xs) value index = if (x == value) then index else find_index xs value index + 1

main :: IO ()
main = do
    hSetBuffering stdout NoBuffering -- DO NOT REMOVE
    
    -- Auto-generated code below aims at helping you parse
    -- the standard input according to the problem statement.
    
    loop
  
loop :: IO ()
loop = do
    --x = []--
    heights <- replicateM 8 $ do
        input_line <- getLine
        let mountainh = read input_line :: Int -- represents the height of one mountain, from 9 to 0.
        --x = mountainh : x
        return (mountainh)
    putStrLn ( show (find_index heights (find_max_element heights) 0 ))
    
    loop

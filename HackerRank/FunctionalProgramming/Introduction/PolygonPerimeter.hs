import Control.Monad

seg_len :: (Int, Int) -> (Int, Int) -> Double
seg_len p1 p2 = (fromIntegral ((fst p1 - fst p2) ^ 2 + (snd p1 - snd p2) ^ 2)) ** 0.5

perimeter :: [(Int, Int)] -> Double
perimeter (p:[]) = 0
perimeter (p1:p2:xs) = seg_len p1 p2 + perimeter (p2:xs)

main :: IO ()
main = do
    n <- getLine
    poly <- replicateM (read n :: Int) $ do
        input_line <- getLine
        let input = words input_line
        return (read (input!!0) :: Int, read (input!!1) :: Int)
    print $ perimeter (poly ++ [head poly])

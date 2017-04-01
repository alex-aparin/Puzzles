import Control.Applicative
import Control.Monad
import System.IO

my_exp :: Double -> Double
my_exp x = foldl (+) 0 (scanl (\r e -> r * x / e) 1 [1..9])

main :: IO ()
main = do
    n_temp <- getLine
    let n = read n_temp :: Int
    args <- replicateM n $ do
        input_line <- getLine
        let x = read input_line :: Double
        return (x)
    mapM (putStrLn . show . my_exp) args
    main
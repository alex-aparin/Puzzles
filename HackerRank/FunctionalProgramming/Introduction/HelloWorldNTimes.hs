import Control.Monad 

main = do
   n <- readLn :: IO Int
   replicateM n (putStrLn "Hello World")
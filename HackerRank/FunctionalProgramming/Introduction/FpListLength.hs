﻿--Only fill up the blanks for the function named len
--Do not modify the structure of the template in any other way
len :: [a] -> Int
len lst = foldl (+) 0 (map (const 1) lst)

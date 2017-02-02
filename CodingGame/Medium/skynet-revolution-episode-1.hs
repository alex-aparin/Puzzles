import System.IO
import Control.Monad
import Data.Maybe

data VertexState = NOT_VISITED | VISITED | GATEWAY deriving(Show)

not_visited :: VertexState -> Bool
not_visited NOT_VISITED = True
--  NOTE: (alex) 
--  It is bottleneck of adj_vs function
not_visited GATEWAY = True
not_visited _ = False

get_result [] = Nothing
get_result (x: xs) = case (x) of Nothing -> Nothing 
                                 Just a -> Just a

change_list_element list index value = 
        (take index list) ++ [value] ++ (drop (index + 1) list)
        
adj_vs :: [VertexState] -> Int -> [Bool] -> Int -> [(Int, Int)]
adj_vs vertices index [] _ = []        
adj_vs vertices index (x:xs) neighbor_index = 
            if (x && (not_visited $ vertices!!index)) then 
                (neighbor_index, index) : (adj_vs vertices (index + 1) xs neighbor_index)
            else adj_vs vertices (index + 1) xs neighbor_index
    
save_gateways :: [VertexState] -> [Int] -> [VertexState]
save_gateways vertices [] = vertices
save_gateways vertices (gateway : other_gateways) = save_gateways updated_vertices other_gateways
        where updated_vertices = change_list_element vertices gateway GATEWAY
        
set_link :: [[Bool]] -> (Int, Int) -> Bool -> [[Bool]]
set_link net edge value = net2
        where net1 = change_list_element net (fst edge) (change_list_element (net!!(fst edge)) (snd edge) value)
              net2 = change_list_element net1 (snd edge) (change_list_element (net1!!(snd edge)) (fst edge) value)
        
save_links :: [[Bool]] -> [(Int, Int)] -> [[Bool]]
save_links network [] = network
save_links network (edge : other_edges) = save_links (set_link network edge True) other_edges

nearest_gateway_edge :: [[Bool]] -> [VertexState] -> [(Int, Int)] -> Maybe (Int, Int)
nearest_gateway_edge network vertices [] = Nothing
nearest_gateway_edge network vertices (edge : edges) = 
            case (vertices!!(snd edge)) of 
                NOT_VISITED -> 
                    nearest_gateway_edge network
                        (
                            change_list_element vertices (snd edge) VISITED
                        ) 
                        (
                            edges ++ (
                                        adj_vs vertices 0 (network!!(snd edge)) (snd edge)
                                     )
                        )
                VISITED -> nearest_gateway_edge network vertices edges
                GATEWAY -> Just edge
        
main :: IO ()
main = do
    hSetBuffering stdout NoBuffering -- DO NOT REMOVE
    
    -- Auto-generated code below aims at helping you parse
    -- the standard input according to the problem statement.
    
    input_line <- getLine
    let input = words input_line
    let n = read (input!!0) :: Int -- the total number of nodes in the level, including the gateways
    let l = read (input!!1) :: Int -- the number of links
    let e = read (input!!2) :: Int -- the number of exit gateways
    
    edges <- replicateM l $ do
        input_line <- getLine
        let input = words input_line
        let n1 = read (input!!0) :: Int -- N1 and N2 defines a link between these nodes
        let n2 = read (input!!1) :: Int
        return (n1, n2)
    
    gateways <- replicateM e $ do
        input_line <- getLine
        let ei = read input_line :: Int -- the index of a gateway node
        return (ei)
    loop (save_links (replicate n $ replicate n False) edges) (save_gateways (replicate n NOT_VISITED) gateways) 

loop :: [[Bool]] -> [VertexState] -> IO ()
loop network vertices = do
    input_line <- getLine
    let gateway_edge = fromJust $ nearest_gateway_edge network vertices [(0, read input_line :: Int)]
    -- hPutStrLn stderr "Debug messages..."
    
    -- Example: 0 1 are the indices of the nodes you wish to sever the link between
    --let gateway_edge = (0, 0)
    --print $ show $ adj_vs vertices 0 (network!!(read input_line :: Int)) 0
    putStrLn $ (show $ fst gateway_edge) ++ " " ++ (show $ snd gateway_edge)
    loop (set_link network gateway_edge False) vertices

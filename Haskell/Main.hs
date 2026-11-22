removeEvens :: [Int] -> [Int]
removeEvens [] = []
removeEvens [x] = [x]
removeEvens (x : y : rest) = x : removeEvens rest

removeOdds :: [Int] -> [Int]
removeOdds (x : y : rest) = y : removeOdds rest
removeOdds _ = []

removeThirds :: [Int] -> [Int]
removeThirds (x : y : z : rest) = x : y : removeThirds rest
removeThirds nums = nums

func :: Int -> [Int] -> Int
func cnt [n] = n
func 1 nums = func 2 (removeEvens nums)
func 2 nums = func 3 (removeOdds nums)
func 3 nums = func 1 (removeThirds nums)

main :: IO ()
main = do
    n <- readLn
    let res = func 1 [1 .. n]
    print res

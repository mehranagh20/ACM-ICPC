import System.IO
import System.Random
import System.Random.Shuffle
import Control.Monad
import Data.Set (Set)
import qualified Data.Set as Set

type Testcase = [(Integer,Integer)]

maxn :: Int
maxn = 2500

writeCase :: FilePath -> Testcase -> IO ()
writeCase f c = withFile f WriteMode $ \hdl -> do
  hSetNewlineMode hdl noNewlineTranslation
  hPutStr hdl $ unlines $ (show $ length c) : [unwords $ map show [a,b] | (a,b) <- c ]

-- this should be in the library somewhere
randomElement :: [a] -> IO a
randomElement as = do
  i <- randomRIO (0,length as-1)
  return $ as !! i

-- second argument is number of different numbers used
randomCase :: Int-> Int -> IO Testcase
randomCase n m = do
  nums <- replicateM m $ randomRIO (-10^6,10^6)
  replicateM n $ do
    a <- randomElement nums
    b <- randomElement nums
    return (a,b)

-- Case with 1 answer
hardCase :: IO Testcase
hardCase = f Set.empty [] where
  f :: Set Integer -> Testcase -> IO Testcase
  f s c | length c > maxn - 3 = return c
  f s c = do
    a <- randomRIO (-10^6,10^6)
    b <- if null c
         then randomRIO (-10^6,10^6)
         else do e <- randomElement (Set.toList s)
                 let ops = (if -10^6 <= a - e && a - e <= 10^6 then (:) (a - e) else id) $ 
                           (if -10^6 <= e - a && e - a <= 10^6 then (:) (e - a) else id) $
                           (if e `mod` a == 0 &&  -10^6 <= e `div` a && e `div` a <= 10^6 then (:) (e `div` a) else id)
                           []
                 if null ops
                 then return 123456789
                 else randomElement ops
    if b == 123456789
    then f s c
    else do
      let anss = [a+b,a-b,a*b]
      let notUsed = filter (`Set.notMember` s) anss
      let nUsed = length notUsed
      f (foldr Set.insert s anss) (replicate nUsed (a,b) ++ c)

main :: IO ()
main = do
  writeCase "secret/03_size_1.in" [(1337,1337)]
  writeCase "secret/04_overflow.in" [(10^6,10^6),(10^6,10^6),(10^6,10^6),(-10^6,10^6),(-10^6,10^6)]
  
  shuffleM ([(toInteger i,1) | i <- [0..maxn-3]] ++ [(713,1),(123,1)]) >>=
    writeCase "secret/01_large_single_sol.in"
  
  shuffleM ([(toInteger i,1) | i <- [0..maxn-4]] ++ [(713,1),(123,1),(512,1)]) >>=
    writeCase "secret/02_large_impossible.in"
  
  hardCase >>= shuffleM >>= writeCase "secret/06_hard_single.in"
  hardCase >>= shuffleM >>= writeCase "secret/07_hard_single.in"
  hardCase >>= shuffleM >>= writeCase "secret/08_hard_single.in"
  hardCase >>= shuffleM >>= writeCase "secret/09_hard_single.in"
  hardCase >>= shuffleM >>= writeCase "secret/10_hard_single.in"

  forM_ [1..5] $ \i -> do
    n <- randomRIO (maxn `div` 2, maxn)
    m <- randomRIO (n `div` 20, n `div` 5)
    randomCase n m >>=
      writeCase ("secret/1" ++ show i ++ "_random.in")
  
  forM_ [21..25] $ \i -> do
    hardCase >>= shuffleM >>= writeCase ("secret/" ++ show i ++ "_hard_single.in")
  
  -- All answers unique
  writeCase "secret/26_allunique.in" [(toInteger i * 3, 1) | i <- [1..maxn]]
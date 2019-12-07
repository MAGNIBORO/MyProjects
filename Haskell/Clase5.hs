f x = x*x

sumaimpar :: Integer -> Integer

sumaimpar n | n==1 = 1
            | n>1  = impar_n + sumaimpar (n-1)
             where impar_n = 2*n-1

tres = 3

factorial :: Integer -> Integer
factorial n | n== 0 = 1
            | n> 0 = n*factorial (n-1)

eprox :: Integer -> Float
eprox n | n==0 = 1
        | n> 0 = 1/(fromInteger (factorial n)) + eprox (n-1)

e = eprox 100

bottom :: Float -> Integer

bottom x | x==0 = 0
         | x> 0 = bottompos x
         | x< 0 = bottomneg x

bottompos i | (i-1) < 0 = 0  
          | otherwise = 1 + bottompos (i-1)

bottomneg i | (i+1) > 0 = 0  
          | otherwise = (-1) + bottomneg (i+1)

division :: Integer -> Integer -> (Integer,Integer)
division a b | a>=0 = divisionpos a b
             | a<0  = divisionneg a b

          
divisionpos :: Integer -> Integer -> (Integer,Integer)
divisionpos a b | b > a = (0,a)
             | b == a = (1,0)
             | (a-b) < b = (1,a-b)
             | otherwise = sumavec ((1,0)) (divisionpos (a-b) b)

divisionneg :: Integer -> Integer -> (Integer,Integer)
divisionneg a b | b > (-a) = (0,a)
             | b == (-a) = (-1,0)
             | ((-a)-b) < b = (-1,a+b)
             | otherwise = sumavec ((-1,0)) (divisionneg (a+b) b)



sumavec :: (Integer,Integer) -> (Integer,Integer) -> (Integer,Integer)
sumavec a b = (fst a + fst b , snd a + snd b)

sumadiv :: Integer -> Integer
sumadiv n = sumadiv_1 n n

sumadiv_1 :: Integer -> Integer -> Integer
sumadiv_1 n k | k== 1 = 1
              | snd (division n k) == 0 = k + sumadiv_1 n (k-1)
              | otherwise = sumadiv_1 n (k-1)

menordiv :: Integer -> Integer
menordiv n | n== 1 = 1 
           | otherwise = menordiv_1 n 2

menordiv_1 :: Integer -> Integer -> Integer
menordiv_1 n k | n==k = k
               | snd(division n k) == 0 = k
               | otherwise = menordiv_1 n (k+1)

doblesum :: Integer -> Integer -> Integer
doblesum a b | a==1 = doblesum_1 1 b
             | a>1 = doblesum_1 a b + doblesum (a-1) b


doblesum_1 :: Integer -> Integer -> Integer
doblesum_1 a b | b == 1 = a
               | b > 1 = a^b + doblesum_1 a (b-1)

fun :: Float -> Integer -> Integer -> Float
fun q n m    | n==1 = q*(fun_1 q m)
             | n>1 = (q^n)*(fun_1 q m) + fun q (n-1) m

fun_1 :: Float -> Integer -> Float
fun_1 q m | m == 1 = q
          | m > 1 = q^m + fun_1 q (m-1) 


        
          
fun2 :: Integer -> Integer -> Float
fun2 n m    | n==1 = fun2_1 m
            | n>1 = (fromInteger n)*( fun2_1 m ) + fun2 (n-1) m

fun2_1 :: Integer -> Float
fun2_1 m | m == 1 = 1
         | m > 1 = (1)/(fromInteger m) + fun2_1 (m-1)
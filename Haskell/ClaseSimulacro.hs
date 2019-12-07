




menorLex :: (Float,Float,Float) -> (Float,Float,Float) -> Bool
menorLex (a,b,c) (d,e,f) | a < d = True
                         | b < e = True
                         | c < f = True
                         | otherwise = False
                         


sumafib :: Integer -> Integer
sumafib n | n==1 = 2
          | n > 1 = sumafib (n-1) + fib n

fib :: Integer -> Integer
fib n | n == 0 = 1
      | n == 1 = 1
      | n > 1 = fib (n-2) + fib (n-1)


esd :: Integer -> Bool
esd n | sum_div n < n = True
      | otherwise = False

suma_diva :: Integer -> Integer -> Integer
suma_diva n k | n==1 = 1
              | k==1 = 1
              | mod n k == 0 = k + suma_diva n (k-1)
              | otherwise = suma_diva n (k-1)

sum_div :: Integer -> Integer
sum_div n = suma_diva n (n-1) 





maxi :: [Integer] -> Integer -> Integer 
maxi (x:xs) a | xs == [] = a
             | a < dist x (head xs) = maxi (xs) (dist x (head xs))
             | otherwise = maxi (xs) a

dist :: Integer -> Integer -> Integer
dist a b = abs (b-a)




comprimir :: [Integer] -> [(Integer,Integer)]
comprimir a = com_aux ( tuplazar (a) )  

tuplazar :: [Integer] -> [(Integer,Integer)]
tuplazar (x:xs) | xs == [] = [(x,1)]
                | otherwise = [(x,1)] ++ tuplazar (xs)

com_aux :: [(Integer,Integer)] -> [(Integer,Integer)]
com_aux (x:xs) | xs == [] = [x]
               | fst x == fst ( head xs ) = com_aux ( [ (fst x , snd x +1) ] ++ tail (xs) )
               | otherwise = [x] ++ com_aux (xs)


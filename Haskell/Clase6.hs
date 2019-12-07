


factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n*factorial (n-1)

y :: Bool -> Bool -> Bool
y True True = True
y _ _ = False

o :: Bool -> Bool -> Bool
o False False = False
o _ _ = True

implica :: Bool -> Bool -> Bool
implica True False = False
implica _ _ = True

suman :: Integer -> Integer
suman n = div (n*(n+1)) 2

es0 :: (Integer,Integer,Integer) -> Bool
es0 (_,_,0) = True
es0 (_,0,_) = True
es0 (0,_,_) = True
es0 (_,_,_) = False

prod :: (Integer,Integer) -> (Integer,Integer) -> Integer
prod (a,b) (c,d) = a*c+b*d

sumadig :: Integer -> Integer
sumadig n | (n>=0) && (n<10) = n
          | otherwise = mod n 10 + sumadig(div n 10)

suma2Primos :: Integer -> Bool
suma2Primos n | n<4 = False
              | otherwise = suma2Primosaux n 2 2

suma2Primosaux :: Integer ->  Integer -> Integer -> Bool
suma2Primosaux n f k |  f==(n-1) = False
                     | (noesprimo f) = suma2Primosaux n (f+1) 2
                     |  k==(n-1) = suma2Primosaux n (f+1) 2
                     | (noesprimo k) = suma2Primosaux n f (k+1) 
                     | n == f + k = True
                     | otherwise = suma2Primosaux n f (k+1) 
                     where noesprimo l= (not (esprimo l))

esprimo :: Integer -> Bool
esprimo 1 = False
esprimo n = not (esDivant n (n-1))


esDivant :: Integer -> Integer -> Bool
esDivant a b | b==1 = False
             | mod a b == 0 = True
             | otherwise = esDivant a (b-1)


collazt :: Integer -> Integer
collazt a = collaztaux a 0


collaztaux :: Integer -> Integer -> Integer
collaztaux a n | a == 1 = (n+1)
            | mod a 2 == 0 = collaztaux (div a 2) (n+1)
            | otherwise = collaztaux (3*a+1) (n+1)

maxcoll ::Integer -> (Integer, Integer)
maxcoll 1 = (1,1)
maxcoll n = maxcollaux n 0 1

maxcollaux :: Integer -> Integer -> Integer -> (Integer, Integer)
maxcollaux n s t | n == 1 = (s,t)
                 | collazt n > s = maxcollaux (n-1) (collazt n) (n)
                 | otherwise = maxcollaux (n-1) s t
               

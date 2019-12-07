f a = a+a

g :: Integer -> Integer -> Bool -> Bool
g x y b = b && (x > y) 

h :: Bool -> Float
h x = pi

doble :: Float -> Float
doble x = x+x

cuadruple :: Float -> Float
cuadruple x = doble (doble x)

esPar :: Integer -> Bool
esPar x | mod x 2 == 0 = True
        | mod x 2 == 1 = False

esMultiplo :: Integer -> Integer -> Bool
esMultiplo x y | mod x y == 0 = True
               | otherwise = False

identidad :: a-> a
identidad x = x

triple :: Num a => a -> a
triple x = x*3

n :: (Num a , Ord b) => a -> b -> a
n a b = 3*a


suma :: Integer -> Integer -> Integer
(suma) x y = x+y

normaVectorial  :: (Float , Float) -> Float
normaVectorial p = sqrt ((fst p) ^ 2 + (snd p) ^ 2)

invertir :: (Float,Float) -> (Float,Float)
invertir a = (snd a , fst a)

crearpar :: Float -> Float -> (Float,Float)
crearpar x y = (x,y)

distancia :: (Float,Float) -> (Float,Float) -> Float
distancia a b = sqrt(  (fst a - fst b)^2 + (snd a - snd b)^2  )


f_1 :: Float -> (Float,Float,Float)
f_1 x = (x*x , 2*x , x-7 )

f_2 :: Integer -> Integer
f_2 x | mod x 2 == 0 = div x 2
      | mod x 2 == 1 = x+1


f_3 :: Integer -> Integer
f_3 n | mod n 6 == 0 = div (n*n) 2
      | otherwise = 3*n+1



f_4 :: (Integer,Integer) -> Integer
f_4 x = fst x * (snd x + 1 )

f_5 ::  (Integer,Integer) -> Integer
f_5 x = f_3 ( f_4 (x))

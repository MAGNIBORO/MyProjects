
import Libreria_clase3

f a = a+a

prod_2 :: Integer -> Integer -> Integer
prod_2 a b = (prod a b )* (prod a b)

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


f_6 :: Float -> Float
f_6 x  | x/= 0 = 1/x



uni :: Integer -> Integer
uni a = mod a 10

triuni :: Integer -> Integer -> Integer -> Integer
triuni a b c = (uni a)+(uni b)+(uni c)

esimpar :: Integer -> Bool
esimpar a | mod a 2 == 1 = True
	  | otherwise =    False

todo_es_impar :: Integer ->  Integer ->  Integer -> Bool
todo_es_impar a b c = ( esimpar a ) && ( esimpar b ) && ( esimpar c )

al_es_impar :: Integer ->  Integer ->  Integer -> Bool
al_es_impar a b c = ( esimpar a ) || ( esimpar b ) || ( esimpar c )

al2_es_impar :: Integer ->  Integer ->  Integer -> Bool
al2_es_impar a b c | ( esimpar a ) && ( esimpar b ) == True = True
	           | ( esimpar a ) && ( esimpar c ) == True = True
                   | ( esimpar b ) && ( esimpar c ) == True = True
                   | otherwise = False



rel1 :: Integer -> Integer -> Bool
rel1 a b  | (esimpar a) == (esimpar b) = True
	    | otherwise = False

rel2 :: Integer -> Integer -> Bool
rel2 a b  | mod (2*a + 3*b) 5 == 0 = True
            | otherwise = False

sondistintos :: Integer -> Integer -> Integer -> Bool
sondistintos a b c | (a/=c) && (a /= b) &&(b /= c) == True = True
                   | otherwise = False

rel3:: Integer -> Integer -> Bool
rel3 a b  | sondistintos (uni a) (uni b) (uni (a*b) ) == True = True
            | otherwise = False


rel4 :: Float -> Float -> Bool
rel4 a b | (a < 3) && (b < 3) == True = True
         | (a < 7) && (a >= 3) && (b >= 3) && (b < 7)  == True = True
	 | (a >= 7) && (b >= 7) == True = True
         | otherwise = False

rel5 :: (Float, Float ) -> (Float, Float )-> Bool
rel5 a b | ( (fst a == 0) && (snd a == 0) ) || ( (fst b == 0) && (snd b == 0) ) == False = rel5aux a b


rel5aux :: (Float, Float ) -> (Float, Float )-> Bool
rel5aux a b | ( (fst a == 0) && (snd a == 0) ) || ( (fst b == 0) && (snd b == 0) ) == True = False
         | ( (fst a / fst b) == (snd a / snd b) ) == True = True
	 | otherwise = False















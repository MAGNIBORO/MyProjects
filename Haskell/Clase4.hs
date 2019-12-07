
factorial :: Integer -> Integer
factorial n | n==0 = 1
            | n>0 = n*  factorial (n-1) 

fib :: Integer -> Integer
fib n | n == 0 = 1
      | n == 1 = 1
      | n >= 2 = fib (n-1) + fib (n-2)

ej :: Integer -> Integer
ej n | n== 1 = 2
     | n>1 = 2*(n-1)*( ej (n-1) ) + (2^(n)) * factorial (n-1)

ej2 :: Integer -> Integer
ej2 n | n==1 = 1
      | n==2 = 2
      | n>2 = (n-2)*(ej2 (n-1) ) + 2*(n-1)*(ej2 (n-2) ) 

espar :: Integer -> Bool
espar n | mod n 2 == 0 = True
        | mod n 2 == 1 = False

ej3 :: Integer -> Integer
ej3 n | n==1 = (-3)
      | n==2 = 6
      | (n>2) && (espar n) = (-3) + (- ej3 (n-1))
      | otherwise = ej3 (n-1) + 2*ej3 (n-2) + 9

sum2n :: Integer -> Integer
sum2n n | n==0 = 1
        | n>0 = 2^n + sum2n (n-1)

sumq :: Integer -> Float -> Float
sumq n q | n==1 = q
         | n>1 = q^n + sumq (n-1) q

sum2q :: Integer -> Float -> Float
sum2q n q | n==0 = 1
          | n>=1 = sumq (2*n) q

sumq2q :: Integer -> Float -> Float
sumq2q n q | n==0 = 1
           | n>=1 = sum2q n q - sumq (n-1) q

mod3 :: Integer -> Bool
mod3 n | n==0 = True
     | n==1 = False
     | n==2 = False
     | n>2 = mod3 (n-3)

sumaImpares :: Integer -> Integer
sumaImpares n | n == 1 = 1
              | n > 1  = (2*n) -1 + sumaImpares (n-1)



mediofac :: Integer -> Integer
mediofac n | n == 1 = 1
           | n == 2 = 2
           | n > 2 = n*mediofac (n-2)




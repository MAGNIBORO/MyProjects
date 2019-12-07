









vacio = []


suma :: [Integer] -> Integer
suma x | x == [] = 0
       | otherwise = (head x) + (suma (tail x))


armar :: a -> a -> [a]
armar x y = [x,y]

pertenece :: Integer -> [Integer] -> Bool
pertenece a m | m == vacio = False
             | a == (head m) = True
             | otherwise = pertenece a (tail m)

listar :: a ->  [a]
listar c = [c]

func :: Eq a => a -> [a] -> Bool
func     a m | m == vacio = False
             | a == (head m) = True
             | otherwise = func a (tail m)


inverr :: [a] -> [a]
inverr x | length x == 1 = x
         | otherwise = ( inverr (tail x) ) ++ (   listar ( head (x) )  )


primermul77 :: [Integer] -> Integer
primermul77 a | mod (head a) 77  == 0 = head a
               | otherwise = primermul77 ( tail a )  


prodd :: [Integer] -> Integer
prodd x | x == [] = 1
       | otherwise = (head x) * (prodd (tail x))




sumaN :: Integer -> [Integer] -> [Integer]
sumaN a [] = vacio
sumaN a lista | length (lista) == 1  = listar ( a + head lista )
              | otherwise = ((  listar (a + head lista ) ) ++ sumaN a ( tail lista) )

sumaprimero :: [Integer] -> [Integer]
sumaprimero x = sumaN (head x) x



pares :: [Integer] -> [Integer]
pares [] = vacio
pares x | mod (head x) 2 == 0 = listar (head x) ++ pares ( tail x)
        | otherwise = pares ( tail x)

quitar :: Integer -> [Integer] -> [Integer]
quitar a [] = vacio
quitar a x | a == (head x) = tail x
           | otherwise = listar (head x ) ++ ( quitar a (tail x) )

hayRepetidos :: [Integer] -> Bool
hayRepetidos [] = False
hayRepetidos x | length x == 1 = False
	       |  pertenece (head x) (tail x) = True
               | otherwise = hayRepetidos (tail x)

eliminarRepetidos :: [Integer] -> [Integer]
eliminarRepetidos [] = vacio
eliminarRepetidos x | pertenece (head x) (tail x) = eliminarRepetidos ( tail x)
                    | otherwise = listar (head x) ++ eliminarRepetidos ( tail x)

maximo :: [Integer] -> Integer
maximo x | length x == 1 = head x
         | (head x ) >= maximo (tail x) = head x
         | otherwise = maximo (tail x)

ordenar :: [Integer] -> [Integer]
ordenar [] = vacio
ordenar x | head x == maximo x = listar ( head x ) ++ ( ordenar (tail x ) )
          | otherwise = ordenar ( (tail x) ++ (listar (head x) ) )

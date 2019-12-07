

-- Trabajo Practico
-- Contando cırculos primos
-- Taller de Algebra 
-- Segundo cuatrimestre 2019



-- Integrantes:
-- 609/14 German Cuacci
-- 410/11 martin nakamura
-- 42360213 matias moran



type Circulo = [Integer]

----------------------------------------------------------sonCirculosIguales----------------------------------------------------------------

sonCirculosIguales :: Circulo -> Circulo -> Bool
sonCirculosIguales [] [] = True
sonCirculosIguales circulo1 circulo2 | (length circulo1) /= (length circulo2) = False
                                     | circulo1 == circulo2 = True
                                     | otherwise = cir_iguales_aux    circulo1    (rotar_izq (circulo1))   circulo2



--simplemente va rotando el circulo1, si alguna rotacion coincide devuelve true , si dio toda la vuelta y llego al circulo original devuelve false
cir_iguales_aux :: Circulo -> Circulo -> Circulo -> Bool
cir_iguales_aux    circulo_orig   circulo_rotado_izq   circulo2 | circulo_orig == circulo_rotado_izq = False
                                                                | circulo_rotado_izq == circulo2 = True
                                                                | otherwise = cir_iguales_aux  circulo_orig  (rotar_izq circulo_rotado_izq)  circulo2



-- "rota" un circulo en forma antihoraria simplemente inserta el primer elemento en la ultima posicion del circulo
rotar_izq :: Circulo -> Circulo
rotar_izq [] = []
rotar_izq (a:as) = as ++ [a]


----------------------------------------------------------permutaciones---------------------------------------------------------------------------------


permutaciones :: Integer -> [[Integer]]
permutaciones 0 = []
permutaciones 1 = [[1]]
permutaciones n = insertar_a_todos n (permutaciones (n-1))


-- para cada uno de sus elementos (listas) , la funcion devuelve todas las posibilidades de insertar un integer en alguna posicion de las mismas
insertar_a_todos :: Integer -> [[Integer]] -> [[Integer]]
insertar_a_todos  a (b:bs) | bs == [] = insertar_en_cada_lugar a b
                           | otherwise = insertar_en_cada_lugar a b ++ insertar_a_todos a bs


-- devuelve todas las posibilidades de insertar un integer en alguna posicion de una lista
insertar_en_cada_lugar :: Integer -> [Integer] -> [[Integer]]
insertar_en_cada_lugar a (b:bs) = insertar_en_cada_lugar_aux a (b:bs) 1


-- auxiliar de la funcion de arriba que lleva cuenta del parametro n que representa la posicion donde se inserta a en la lista b y va recorriendo todas las posiciones de b , devolviendo finalmente lo que se pedia en la funcion de arriba
insertar_en_cada_lugar_aux :: Integer -> [Integer] -> Integer -> [[Integer]]
insertar_en_cada_lugar_aux a (b:bs) n | fromInteger (n)  == length (b:bs) + 1 = [insertar_en_posicion a (b:bs) n ]
                                      | otherwise =  insertar_en_posicion a (b:bs) n : insertar_en_cada_lugar_aux a (b:bs) (n+1)

                                      
-- dado un integer a , una lista b y una posicion n de la lista b , inserta a en esa posicion
insertar_en_posicion :: Integer -> [Integer] -> Integer -> [Integer]
insertar_en_posicion a b n = lista_hasta b (n-1) ++ [a] ++ lista_desde b (n)


-- devuelve una lista "cortada" de la lista b desde la posicion 1 hasta n
lista_hasta :: [Integer] -> Integer -> [Integer]
lista_hasta _ 0 = []
lista_hasta (b:bs) n = b : lista_hasta bs (n-1)


-- devuelve una lista "cortada" de la lista b desde la posicion n hasta el final de la lista b
lista_desde :: [Integer] -> Integer -> [Integer]
lista_desde (b:bs) 1 = (b:bs)
lista_desde (b:bs) n | fromInteger(n) == 1 + length (b:bs) = []
                     | otherwise = lista_desde bs (n-1) 



----------------------------------------------------------esCirculoPrimo---------------------------------------------------------------------------------

esCirculoPrimo :: Circulo -> Bool
esCirculoPrimo [] = False
esCirculoPrimo [1] = False
esCirculoPrimo circulo = esCirculoPrimo_aux circulo (rotar_izq circulo)


--auxilir de la funcion de arriba que simplemente recorre y compara 2 elementos consecutivos de un circulo hasta que llega al principio , donde devuelve True.
esCirculoPrimo_aux :: Circulo -> Circulo -> Bool
esCirculoPrimo_aux   circulo_orig   circulo  | not (esPrimo  ( head circulo + head ( tail circulo) )) = False
                                             | circulo_orig /= circulo = esCirculoPrimo_aux circulo_orig  (rotar_izq circulo)
                                             | otherwise = True


-- funcion que nos dice si un numero es primo
esPrimo :: Integer -> Bool
esPrimo 1 = False
esPrimo n = not (existeDivisor n (n-1))


-- funcion que nos dice si existe un divisor distinto de uno para un numero n
existeDivisor :: Integer -> Integer -> Bool
existeDivisor a b | b==1 = False
                  | mod a b == 0 = True
                  | otherwise = existeDivisor a (b-1)


----------------------------------------------------------estaRepetidoPrimero---------------------------------------------------------------------------------


estaRepetidoPrimero :: [Circulo] -> Bool
estaRepetidoPrimero [] = False
estaRepetidoPrimero circulos = estaRepetidoPrimero_aux (head circulos) circulos


-- auxiliar de la funcion de arriba que lleva compara el primer circulo de una lista con todos los demas
estaRepetidoPrimero_aux  :: Circulo -> [Circulo] -> Bool
estaRepetidoPrimero_aux _ [] = False
estaRepetidoPrimero_aux a (x:xs) | length (x:xs)  == fromInteger(1) = False
                                 | sonCirculosIguales a (head (xs)) = True
                                 | otherwise = estaRepetidoPrimero_aux a xs


----------------------------------------------------------listaCirculosPrimos---------------------------------------------------------------------------------

listaCirculosPrimos :: Integer -> [Circulo]
listaCirculosPrimos 0 = []
listaCirculosPrimos n = extraerCirculosNoPrimos ( extraerCirculosRotados (permutaciones n))


--extre los circulos duplicados de una lista de circulos debidos a rotaciones
extraerCirculosRotados :: [Circulo] -> [Circulo]
extraerCirculosRotados (x:xs)    | xs == [] = [x]
                                 | estaRepetidoPrimero (x:xs) = extraerCirculosRotados xs
                                 | otherwise = x : extraerCirculosRotados xs


-- extrae los circulos que no son primos de una lista
extraerCirculosNoPrimos :: [Circulo] -> [Circulo]
extraerCirculosNoPrimos  (x:xs) | (esCirculoPrimo x) && ( xs==[] ) = [x]
                                | not (esCirculoPrimo x) && ( xs==[] ) = []
                                | esCirculoPrimo x = x : extraerCirculosNoPrimos xs
                                | otherwise = extraerCirculosNoPrimos xs


----------------------------------------------------------contarCirculosPrimos---------------------------------------------------------------------------------


contarCirculosPrimos :: Integer -> Integer
contarCirculosPrimos n = toInteger( length (listaCirculosPrimos n) )

----------------------------------------------------------listaCirculosPrimosEspejados---------------------------------------------------------------------------------


listaCirculosPrimosEspejados :: Integer -> [Circulo]
listaCirculosPrimosEspejados n = extraerCirculosEspejados (listaCirculosPrimos n)


--extrae circulos espejados de una lista
extraerCirculosEspejados :: [Circulo] -> [Circulo]
extraerCirculosEspejados [] = []
extraerCirculosEspejados [[1]] = []
extraerCirculosEspejados (x:xs)  | xs == [] = [x]
                                 | estaEspejadoPrimero (x:xs) = extraerCirculosEspejados xs
                                 | otherwise = x : extraerCirculosEspejados xs


-- funcion que no dice si el primer elemento de una lista esta espejado con algun otro 
estaEspejadoPrimero :: [Circulo] -> Bool
estaEspejadoPrimero [] = False
estaEspejadoPrimero circulos = estaEspejadoPrimero_aux (head circulos) circulos


estaEspejadoPrimero_aux  :: Circulo -> [Circulo] -> Bool
estaEspejadoPrimero_aux _ [] = False
estaEspejadoPrimero_aux a (x:xs) | sonCirculosEspejados a (head (xs)) = True
                                 | otherwise = estaEspejadoPrimero_aux a xs


-- funcion que nos dice si 2 circulos son espejados
sonCirculosEspejados :: Circulo -> Circulo -> Bool
sonCirculosEspejados circulo1 circulo2 = sonCirculosIguales circulo1 (espejar circulo2)


-- funcion que espeja un circulo
espejar :: Circulo -> Circulo
espejar [] = []
espejar (x:xs) = espejar xs ++ [x]
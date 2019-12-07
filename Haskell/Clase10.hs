


type Polinomio = [Float]


grado :: Polinomio -> Integer
grado a = toInteger (length a) - 1

evaluar :: Polinomio -> Float -> Float
evaluar (a:as) x | as == [] = a
                 | otherwise = a*x^(grado (a:as)) + evaluar as x

derivada :: Polinomio -> Polinomio
derivada (a:as) | as == [] = []
                | otherwise = [ a * fromInteger(  grado (a:as) ) ] ++ derivada as


derivadaN :: Integer -> Polinomio -> Polinomio
derivadaN 1 a = derivada a
derivadaN n a = derivadaN (n-1) (derivada a)



suma  :: Polinomio -> Polinomio -> Polinomio
suma a b = limpiar (suma_aux a b)


suma_aux :: Polinomio -> Polinomio -> Polinomio
suma_aux (a:as) (b:bs) | grado (b:bs) > grado (a:as) = suma_aux (b:bs) (a:as)
                       | grado (a:as) == 0 = [ a + b]
                       | grado (a:as) == grado (b:bs) = ( a+b ) : suma_aux as bs
                       | otherwise = a : suma_aux as (b:bs)


limpiar :: Polinomio -> Polinomio
limpiar (a:as) | a == 0 = as
               | otherwise = (a:as)



productoPorEscalar :: Float -> Polinomio -> Polinomio
productoPorEscalar 0 _ = [0]
productoPorEscalar n (a:as) | as == [] = [n*a]
                            | otherwise =  n*a : productoPorEscalar n as


productoPorMonomio :: (Float, Integer) -> Polinomio -> Polinomio
productoPorMonomio (a,b) (c:cs) | b == 0 = productoPorEscalar a (c:cs)
                                | cs == [] = productoPorEscalar (a*c) (n_potencia b)
                                | otherwise =  suma (productoPorEscalar ( a*c ) (n_potencia ( b + grado (c:cs) ))) (productoPorMonomio (a,b) cs)


rellenar_ceros_desde :: Integer -> Polinomio
rellenar_ceros_desde 0 = [0]
rellenar_ceros_desde n = 0 : rellenar_ceros_desde (n-1)

n_potencia :: Integer -> Polinomio
n_potencia 0 = [0]
n_potencia n = 1 : rellenar_ceros_desde (n-1)



producto :: Polinomio -> Polinomio -> Polinomio
producto (a:as) (b:bs) | bs == [] = productoPorEscalar b (a:as)
                       | as == [] = productoPorMonomio (a,grado (a:as)) (b:bs)
                       | otherwise = suma (productoPorMonomio (a,grado (a:as)) (b:bs) ) ( producto as (b:bs) )


type Complejo = (Float, Float)

suma_c :: Complejo -> Complejo -> Complejo
suma_c (a,b) (c,d) = (a+c,b+d)

prod_c :: Complejo -> Complejo -> Complejo
prod_c (a,b) (c,d) = (a*c-b*d , a*d + b*c)

pote_c :: Complejo -> Integer -> Complejo
pote_c (a,b) 0 = (1,0)
pote_c (a,b) 1 = (a,b)
pote_c (a,b) n = prod_c (a,b) ( pote_c (a,b) (n-1) )


evaluarComplejo :: Polinomio -> Complejo -> Complejo
evaluarComplejo (a:as) x | as == [] = (a,0)
                         | otherwise = suma_c (prod_c (a,0) ( pote_c x (grado (a:as) ) ) ) (evaluarComplejo as x)
















type Set a = [a]

vacio :: Set Integer
vacio = []

agregar :: Integer -> Set Integer -> Set Integer
agregar x a | elem x a = a
            | otherwise = a ++ [x]

agregarATodos :: Integer -> Set (Set Integer) -> Set (Set Integer)
agregarATodos n (x:xs) | (xs) == [] = [agregar n x] 
                       | otherwise = ( (agregar n x) : agregarATodos n xs )

partes :: Integer -> Set (Set Integer)
partes 0 = []
partes 1 = [[],[1]]
partes n = agregarATodos n (partes (n-1)) ++ partes (n-1)

productoCartesiano :: Set Integer -> Set Integer -> Set (Integer, Integer)
productoCartesiano [] _ = []
productoCartesiano _ [] = []
productoCartesiano (a:as) (b:bs) | bs == [] = auxfun (a:as) b
                                 | otherwise = auxfun (a:as) b ++ productoCartesiano (a:as) bs

auxfun :: Set Integer -> Integer -> Set (Integer,Integer)
auxfun [] _ = []
auxfun (a:as) b | as == [] = [(a,b)]
                | otherwise = [(a,b)] ++ auxfun as b


variaciones :: Set Integer -> Integer -> Set [Integer]
variaciones [] _ = [[]]
variaciones _ 0 = [[]]
variaciones a 1 = elegir a
variaciones (a:as) n = procar (elegir (a:as)) (variaciones (a:as) (n-1))


elegir :: Set Integer -> Set (Set Integer)
elegir (a:as) | as == [] = [[a]]
              | otherwise = [a] : elegir as



procar ::  Set (Set Integer) -> Set [Integer] -> Set [Integer]
procar (a:as)  (b:bs)| as == [] = agregarATodosforce (head a) (b:bs)
                     | bs == [] = ( b ++ a) : ( procar (as) (b:bs) )
                     | otherwise = agregarATodosforce (head a) (b:bs) ++ procar (as)  (b:bs)


agregarATodosforce :: Integer -> Set (Set Integer) -> Set (Set Integer)
agregarATodosforce n (x:xs) | (xs) == [] = [ x ++ [n]] 
                            | otherwise = ( (  x ++ [n]) : agregarATodosforce n xs )


insertarEn :: [Integer] -> Integer -> Integer -> [Integer]
insertarEn a n 1 = n : a
insertarEn a n k | fromInteger(k) == (length a + 1) = a ++ [n]
                 | otherwise = hasta a (k-1) ++ [n] ++ desde a (k)

hasta :: [Integer] -> Integer -> [Integer]
hasta (a:as) n | fromInteger(n) == length (a:as) = (a:as)
               | n == 1 = [a]
               | otherwise = a : hasta (as) (n-1)

desde :: [Integer] -> Integer -> [Integer]
desde (a:as) n | n == 1 = (a:as)
               | fromInteger(n) == length (a:as) = [last (a:as)]
               | otherwise = desde as (n-1)

insertarEnconj :: [[Integer]] -> Integer -> Integer -> [[Integer]]
insertarEnconj [] n _ = [[n]]
insertarEnconj (a:as) n k | as == [] = [insertarEn a n k]
                          | otherwise = (insertarEn a n k ) : insertarEnconj as n k


permutaciones :: Integer -> Set [Integer]
permutaciones 0 = []
permutaciones 1 = [[1]]
permutaciones n = permaux n n 

permaux :: Integer -> Integer -> Set [Integer]
permaux 0 _ = []
permaux 1 _ = [[1]]
permaux a 1 = insertarEnconj permaux (n-1) n 1
permaux a b = insertarEnconj permaux (n-1) n b ++ permaux a (b-1)
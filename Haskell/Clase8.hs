


type Set a = [a]

vacio :: Set Integer
vacio = []



agregar :: Integer -> Set Integer -> Set Integer
agregar x a | elem x a = a
            | otherwise = x : a



incluido :: Set Integer -> Set Integer -> Bool
incluido (a:as) (b:bs) | not (elem a (b:bs)) = False
                       | (as) == vacio = True
                       | otherwise = incluido (as) (b:bs)


iguales :: Set Integer -> Set Integer -> Bool
iguales (a:as) (b:bs) = (incluido (a:as) (b:bs)) &&  (incluido (b:bs) (a:as))


agregarC :: Set Integer -> Set (Set Integer) -> Set (Set Integer)
agregarC x a | elem x a = a
             | otherwise = x : a

agregarATodos :: Integer -> Set (Set Integer) -> Set (Set Integer)
agregarATodos x (a:as) | (as) == [] = [agregar x a]
                       | otherwise = agregarC (agregar x a) (agregarATodos x (as))
                       

partes :: Integer -> Set (Set Integer)
partes 0 = [vacio]
partes n = (partes (n-1)) ++ (agregarATodos n (partes (n-1)) )


productoCartesiano :: Set Integer -> Set Integer -> Set (Integer, Integer)
productoCartesiano _ [] = []
productoCartesiano [] _ = []
productoCartesiano (a:as) b      | (as) == vacio = agregarATodosdupla a b
                                 | otherwise = (agregarATodosdupla a b) ++ (productoCartesiano (as) b)

agregarATodosdupla :: Integer -> Set Integer -> Set (Integer,Integer)
agregarATodosdupla a (b:bs)     | (bs) == [] = [(a,b)]
                                | otherwise = (a,b) : agregarATodosdupla a (bs)


insertarEn :: [Integer] -> Integer -> Integer -> [Integer] 
insertarEn a b c | c == 1 = b : a 
                 | (fromInteger(c) == length a + 1) = a ++ [b]
                 | c > 1 = (listahasta a (c-1)) ++ ([b]) ++ (listadesde a c)

listadesde :: [Integer] -> Integer -> [Integer]
listadesde (a:as) 1 = (a:as)
listadesde (a:as) b   | fromInteger(b) == (length (a:as) + 1) = []
                      | b> 1 = listadesde (as) (b-1)

listahasta :: [Integer] -> Integer -> [Integer]
listahasta (a:as) b     | fromInteger(b) == (length (a:as)) = (a:as)
                        | b == 1 = [a]
                        | b> 1 = listahasta ( init (a:as) ) (b)


insertar_En :: [[Integer]] -> Integer -> Integer -> [[Integer]] 
insertar_En (a:as) b c | c == 1 = agregarATodos b (a:as)
                       | ((as) == []) = [insertarEn a b c]
                       | c > 1 = ((listahasta a (c-1)) ++ ([b]) ++ (listadesde a c) ) : insertar_En (as) b c


permutaciones :: Integer -> Integer -> [[Integer]]
permutaciones 0 _ = []
permutaciones 1 _ = [[1]]
permutaciones n c |  c == n =  (insertar_En (permutaciones (n-1) 1) n n)
                  |  c >= 1 = (insertar_En (permutaciones (n-1) 1) n c) ++ permutaciones n (c+1)  


agregarconjunto :: [[Integer]] -> [Integer] -> [[Integer]] 
agregarconjunto a b c | c == 1 = b : a 
                 | (fromInteger(c) == length a + 1) = a ++ [b]
                 | c > 1 = (listahasta a (c-1)) ++ ([b]) ++ (listadesde a c)


bolitas :: Integer -> Integer -> [[Integer]]
bolitas k 0 = []
bolitas 0 n = [] : bolitas 0 (n-1)
bolitas k 1 = [[1..k]]
bolitas 1 n = [] : bolitas 0 (n-1) [1] a
                  



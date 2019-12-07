



estanrel :: Integer -> Integer -> Bool
estanrel 0 _ = False
estanrel _ 0 = False
estanrel a b | mod a b == 0 = True
             | otherwise = False


prod :: Integer -> Integer
prod n = prod_aux (2*n)

prod_aux :: Integer -> Integer
prod_aux 2 = 24
prod_aux n = (n*n + 2*n ) * prod_aux (n-1)


esPrimo
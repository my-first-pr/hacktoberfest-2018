--First steps in Higher Order Functions

divideByTen :: (Floating a) => a -> a
divideByTen = (/10) 

divideTenBy :: (Floating a) => a -> a
divideTenBy = (10/)

subtractFour :: (Num a) => a -> a
subtractFour = (subtract 4)
--subtract a b returns b-a
-- subtract :: Num a => a -> a -> a
--subtract a returns (a -> a) - a function that takes one parameter and subtracts the already given one from it


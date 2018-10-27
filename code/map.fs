let rec map f = function
  | [] -> []
  | x::xs -> f x :: mymap f xs;;

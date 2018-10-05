let subset la lb =
match (la, lb) with
| ([], lb) -> true
| (la, []) -> false
| (la, lb) ->
  let inlb a = List.mem a lb in
  List.for_all inlb la;;


let equal_sets a b =
  if subset a b && subset b a then true else false;;

let set_union a b =
  let sa = List.fast_sort compare a in
  let sb = List.fast_sort compare b in
  let l1 = List.merge compare sa sb in
  List.sort_uniq compare l1;;
    
let set_intersection a b =
  let sa = List.sort_uniq compare a in
  let sb = List.sort_uniq compare b in
  let inb x = List.mem x sb in
  List.filter inb sa;;

let set_diff a b = 
  let sa = List.sort_uniq compare a in
  let sb = List.sort_uniq compare b in
  let notinb x = not (List.mem x sb) in
  List.filter notinb sa;;

let rec computed_fixed_point eq f x =
  let newx = f x in
  if (eq newx x) then x else computed_fixed_point eq f newx;;

let rec computed_periodic_point eq f p x =
  if p = 0 then x else
  let rec compute f p x = 
    if (p = 1) then f x
    else compute f (p-1) (f x) in

  let newx = compute f p x in
  if (eq newx x) then x
  else computed_periodic_point eq f p (f x);;

let while_away s p x =
  let rec test_loop s p x list = 
    if not (p x) then list
    else 
      test_loop s p (s x) (x::list) in

  List.rev (test_loop s p x []);;

let rle_decode lp =
  let rec loop_the_list iter len list =
    if(iter = len) then list else
      let pair = List.nth lp iter in
      let num = fst pair in
      let elem = snd pair in

      let rec sublist_construct n list = 
        if (n=0) then list else
          sublist_construct (n-1) (elem::list) in

      loop_the_list (iter+1) len (List.append list (sublist_construct num [])) in

  loop_the_list 0 (List.length lp) [];;


type ('nonterminal, 'terminal) symbol = N of 'nonterminal | T of 'terminal;;

(*Valid symbol can be eventually transferred to terminal symbol*)
(* rules is a list of rule*)
(*rule is pair (symbol, rhs)*)
(*rhs is a list of T/N*)
let rec isValid rhs list_of_valid_symbols =
match rhs with
| [] -> true
| ((T s)::t) -> isValid t list_of_valid_symbols
| ((N s)::t) -> if (List.mem s list_of_valid_symbols)
      then isValid t list_of_valid_symbols
      else false;;

let rec find_valid_symbol rules list_of_valid_symbols =
match rules with
| [] ->List.sort_uniq compare list_of_valid_symbols
| (s, rhs)::t -> if isValid rhs list_of_valid_symbols 
          then find_valid_symbol t (s::list_of_valid_symbols)
          else find_valid_symbol t list_of_valid_symbols;;

let filter_blind_alleys g =
  let (start, rules) = g in
  let loop list= 
    let new_list = find_valid_symbol rules list in
    if equal_sets list new_list
     then new_list
    else find_valid_symbol rules new_list in
  let valid_symbols = loop [] in
  
  let is_valid_rule (s, rhs) = 
   (List.mem s valid_symbols) && isValid rhs valid_symbols in

  start, List.filter is_valid_rule rules;;

(* 
   compress: char list -> (char * int) list
   This function compresses a list of characters by grouping consecutive identical characters 
   and counting their occurrences.
*)

(* Base case: If the input list is empty, return an empty list *)
fun compress [] = []

  (* Recursive case: Start processing from the first character x and the rest of the list xs *)
  | compress (x::xs) = 
      let
        (* 
           Inner helper function: count
           Parameters:
           - []: the remaining characters to process
           - c: the current character being counted
           - n: how many times we've seen this character consecutively
           - acc: an accumulator list of (char, count) pairs we've built so far
        *)

        fun count ([], c, n, acc) = 
              (* If we reach the end of the list, append the final (char, count) to the accumulator *)
              acc @ [(c, n)]

          | count (y::ys, c, n, acc) =
              if y = c then 
                (* If current character y matches the one we're counting (c), increment count n *)
                count (ys, c, n+1, acc)
              else 
                (* If character changes, flush the previous (c, n) to the accumulator,
                   and start counting new character y with count 1 *)
                count (ys, y, 1, acc @ [(c, n)])

      in
        (* Begin counting with the first character x, an initial count of 1, and an empty accumulator *)
        count(xs, x, 1, [])
      end;

(* compress [#"a", #"a", #"a", #"b", #"b", #"c", #"c", #"c", #"d"]; *)
(* > val it = [(#"a",3),(#"b",2),(#"c",3),(#"d",1)] : (char * int) list *)

% Base case: if the input list is empty, the result is also an empty list.
compress([], []).

% Recursive case:
% Start the compression by taking the head H of the list and begin tracking its count as 1.
% T is the tail of the list (rest of the characters).
% We then call the helper predicate compress_helper to process the rest of the list.
compress([H|T], Result) :-
    compress_helper(T, H, 1, [], Result).


% Base case for the helper:
% When the input list is empty (i.e., we've reached the end),
% we finalize by appending the last character (Char) and its count (Count)
% to the accumulator Acc and unify that with the final Result.
compress_helper([], Char, Count, Acc, Result) :-
    append(Acc, [Char, Count], Result).


% Recursive case for the helper:
compress_helper([H|T], Char, Count, Acc, Result) :-
    (
        H = Char ->
            % If the next character H is the same as the current tracked Char,
            % we increment the Count and continue processing the tail T
            NewCount is Count + 1,
            compress_helper(T, Char, NewCount, Acc, Result)
        ;
            % If H is different from Char, we've finished a run of Char.
            % Add Char and its Count to the accumulator Acc as a pair.
            % Then start a new run with H and a count of 1.
            append(Acc, [Char, Count], NewAcc),
            compress_helper(T, H, 1, NewAcc, Result)
    ).

% ?- compress("aaabbbcccd", R).
% R = ['a', 3, 'b', 3, 'c', 3, 'd', 1].

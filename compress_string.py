def compress_string(s):
    # Base case: if the input string is empty, just return it
    if not s:
        return s

    # 'result' will hold the compressed pieces as we build them (e.g., ['a3', 'b2'])
    result = []

    # 'count' tracks how many times the current character has been seen consecutively
    count = 1

    # Loop through the string starting from the second character (index 1)
    for i in range(1, len(s)):
        # Check if current character is the same as the previous one
        if s[i] == s[i-1]:
            # If so, increment the count (we're still on a run of the same character)
            count += 1
        else:
            # If not, we've reached the end of a repeated sequence
            # Append the previous character and its count to the result list
            result.append(s[i-1] + str(count))

            # Reset count to 1 for the new character sequence
            count = 1

    # After the loop ends, we still need to add the last character + its count
    result.append(s[-1] + str(count))

    # Join all the elements in the result list into a single compressed string
    compressed = ''.join(result)

    # Only return the compressed string if it's shorter than the original
    # Otherwise, return the original string (since compression isn't beneficial)
    return compressed if len(compressed) < len(s) else s

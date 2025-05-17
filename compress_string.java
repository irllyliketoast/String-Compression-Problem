// Define a public class named StringCompressor
public class StringCompressor {

    // Static method to compress a given input string using run-length encoding
    public static String compress(String s) {
        
        // Edge case: if the string is null or empty, return it as-is
        if (s == null || s.length() == 0) return s;

        // StringBuilder is used to efficiently build the compressed string
        StringBuilder sb = new StringBuilder();

        // Initialize a counter to track how many times a character repeats consecutively
        int count = 1;

        // Loop through the string starting from index 1 (since we compare with the previous character)
        for (int i = 1; i < s.length(); i++) {
            
            // If the current character is the same as the previous one, increment the count
            if (s.charAt(i) == s.charAt(i - 1)) {
                count++;
            } else {
                // If the character changes:
                // Append the previous character and its count to the StringBuilder
                sb.append(s.charAt(i - 1)).append(count);

                // Reset the count for the new character
                count = 1;
            }
        }

        // After the loop, we need to handle the final group of characters (which isn't appended yet)
        sb.append(s.charAt(s.length() - 1)).append(count);

        // Convert the StringBuilder to a String
        String compressed = sb.toString();

        // Return the compressed string only if it's shorter than the original
        // Otherwise, return the original string to avoid unnecessary bloat
        return compressed.length() < s.length() ? compressed : s;
    }
}

// StringCompressor.compress("aaabbbcccd");
// Returns: "a3b3c3d1"

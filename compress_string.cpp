#include <iostream>   // For input/output (not directly used here, but useful for testing)
#include <string>     // Required for std::string and related operations
using namespace std;  // Brings std namespace into global scope (e.g., so we can use 'string' directly)

// Define a class called StringCompressor
class StringCompressor {
public:

    // Define a static method 'compress' that takes a constant reference to a string
    // and returns a compressed version of it using run-length encoding
    static string compress(const string& s) {
        
        // If the string is empty, return it immediately (base case)
        if (s.empty()) return s;

        // Result string to hold the compressed version
        string result;

        // Counter to track how many times the current character repeats
        int count = 1;

        // Loop through the string starting from the second character
        for (size_t i = 1; i < s.length(); ++i) {
            
            // If the current character is the same as the previous one, increment the count
            if (s[i] == s[i-1]) {
                ++count;
            } else {
                // If the character changes:
                // Append the previous character and its count to the result string
                // Note: s[i-1] is the last character of the current run
                result += s[i-1] + to_string(count);

                // Reset count to 1 for the new character
                count = 1;
            }
        }

        // After the loop, append the last character and its count
        // s.back() is the last character of the original string
        result += s.back() + to_string(count);

        // Return the compressed string only if it's shorter than the original
        // Otherwise, return the original string
        return result.length() < s.length() ? result : s;
    }
};

// #include <iostream>

// int main() {
    // cout << StringCompressor::compress("aaabbbcccd") << endl;    Output: a3b3c3d1
    // cout << StringCompressor::compress("abc") << endl;           Output: abc (not shorter)
    // return 0;
// }

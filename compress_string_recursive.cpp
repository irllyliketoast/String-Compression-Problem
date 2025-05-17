#include <iostream>
#include <string>
using namespace std;

class StringCompressor {
public:
    // Public interface
    static string compress(const string& s) {
        // If empty, return early
        if (s.empty()) return s;

        // Call the recursive helper starting from index 1
        string compressed = compressHelper(s, 1, s[0], 1, "");

        // Return the compressed version only if it's shorter
        return compressed.length() < s.length() ? compressed : s;
    }

private:
    // Recursive helper function:
    // - s: the original string
    // - index: current index in the string
    // - currentChar: the character we're currently counting
    // - count: how many times currentChar has occurred consecutively
    // - acc: accumulated compressed result as a string
    static string compressHelper(const string& s, size_t index, char currentChar, int count, const string& acc) {
        // Base case: reached the end of the string
        if (index == s.length()) {
            // Append the last character group and return the result
            return acc + currentChar + to_string(count);
        }

        // Recursive case:
        if (s[index] == currentChar) {
            // Same character, increment count and continue
            return compressHelper(s, index + 1, currentChar, count + 1, acc);
        } else {
            // Character changed:
            // 1. Append current group to acc
            // 2. Start counting new character from 1
            string updatedAcc = acc + currentChar + to_string(count);
            return compressHelper(s, index + 1, s[index], 1, updatedAcc);
        }
    }
};


// int main() {
    // cout << StringCompressor::compress("aaabbbcccd") << endl;     Output: a3b3c3d1
    // cout << StringCompressor::compress("aabbcc") << endl;         Output: aabbcc
    // return 0;
// }

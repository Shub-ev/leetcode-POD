/*
 * Problem Statement: 1667. Number of Strings That Appear as Substrings in Word
 * Given an array of strings patterns and a string word, return the number of strings in patterns
 * that exist as a substring in word.
 * A substring is a contiguous sequence of characters within a string.
 * 
 * Example 1:
 * Input: patterns = ["a","abc","bc","d"], word = "abc"
 * Output: 3
 * Explanation:
 * - "a" appears as a substring in "abc".
 * - "abc" appears as a substring in "abc".
 * - "bc" appears as a substring in "abc".
 * - "d" does not appear as a substring in "abc".
 * 3 of the strings in patterns appear as a substring in word.
 * 
 * Example 2:
 * Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
 * Output: 2
 * Explanation:
 * - "a" appears as a substring in "aaaaabbbbb".
 * - "b" appears as a substring in "aaaaabbbbb".
 * - "c" does not appear as a substring in "aaaaabbbbb".
 * 2 of the strings in patterns appear as a substring in word.
 * 
 * Example 3:
 * Input: patterns = ["a","a","a"], word = "ab"
 * Output: 3
 * Explanation: Each of the patterns appears as a substring in word "ab".
 *
 * Constraints:
 * 1 <= patterns.length <= 100
 * 1 <= patterns[i].length <= 100
 * 1 <= word.length <= 100
 * patterns[i] and word consist of lowercase English letters.
 */

// Optimal Solution: O(n * m) time complexity, where n is the number of patterns and m is the length of the word.
// Time complexity: O(n * m), where n is the number of patterns and m is the length of the word.
// Space complexity: O(1), as we are using a constant amount of extra space.

// Explanation: The solution iterates through each pattern in the patterns array and checks if it exists as
// a substring in the word using the find() function. If it does, we increment the count. Finally, we return
// the count of patterns that are substrings of the word.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(string p :patterns){
            // Check if the pattern exists as a substring in the word
            // p.npos => a constant representing the maximum value for size_t, which indicates that the substring was not found.
            // word.find(p) => returns the starting index of the first occurrence of the substring p in word, or string::npos if not found.
            if(word.find(p)!=p.npos){
                ans ++;
            }
        }
        return ans ;
    }
};
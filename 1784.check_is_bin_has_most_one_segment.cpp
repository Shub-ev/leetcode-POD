/*
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains
at most one contiguous segment of ones. Otherwise, return false.

Example 1:
Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.

Example 2:
Input: s = "110"
Output: true 

Constraints:
1 <= s.length <= 100
s[i]​​​​ is either '0' or '1'.
s[0] is '1'.
*/

/*
 * As per problem statement there should be only 1 contigious segment of 1s.
 * Also, they have mentioned there will be no leading zeros, which means we have
 * out first contigious segment at start (even if one 1 it is a valid segment).
 * 
 * So now our task is to check if there is another such segment.
 * If yes return false.
 * If no return true.
 * 
*/
#include <iostream>
class Solution {
public:
    bool checkOnesSegment(std::string s) {
        int n = s.length();
        int i = 0;

        // Skip the first segment of 1s
        while(true) {
            if(s[i] == '1') i++;
            else break;
        }
        // Skip if any 0s after first segment
        while(true) {
            if(s[i] == '0') i++;
            else break;
        }

        // check if length of string is equal to index
        // if not it is clear that there are still elements to be iterated
        // and those are 1s (i.e. another segment)
        return n==i;
    }
};
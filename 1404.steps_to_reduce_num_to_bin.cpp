/*
Given the binary representation of an integer as a string s, return the
number of steps to reduce it to 1 under the following rules:
1. If the current number is even, you have to divide it by
2. If the current number is odd, you have to add 1 to it.
It is guaranteed that you can always reach one for all test cases.

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4. 
Step 5) 4 is even, divide by 2 and obtain 2.
Step 6) 2 is even, divide by 2 and obtain 1.

Example 2:
Input: s = "10"
Output: 1
Explanation: "10" corresponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  

Example 3:
Input: s = "1"
Output: 0

Constraints:
1 <= s.length <= 500
s consists of characters '0' or '1'
s[0] == '1'
*/


/*
 * Solution:
 * We will start from end of the string.
 * If we have 1 then we have to perform 2 steps.
 * 1. Add 1 to the binary & make it even.
 * 2. Divide by 2 (right shift >> by 1).
 *
 * If we have 0 at the end.
 * 1. Then just divide by 2
 *
 * ### We have 2 solutions ###
 * 1. Convert string to number then do math recursively till we get 1.
 * -> as the number string is so long (read constraints) this is not practical.
 *
 * 2. Use below method.
 * A. Read the string from end.
 * B. If last element is 1 or if carry is one (not both) then our last element
 *    is odd which results in step += 2 and carry = 1.
 * C. If last element is 0 then just right shift by one which is step += 1.
 *
 * As input is a string and we dont want to invent time to convert it to number
 * we are just assuming the operations and couting the steps accordingly.
 */
class Solution {
public:
    int numSteps(string s) {
        int carry = 0, step = 0;
        int n = s.length();

        for(int i = n-1; i > 0; i--) {
            if((s[i] == '1') + carry == 1) {
                step += 2;
                carry = 1;
            } else 
                step += 1;
        }
        return step + carry;
    }
};

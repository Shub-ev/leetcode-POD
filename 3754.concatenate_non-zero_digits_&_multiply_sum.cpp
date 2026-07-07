/*
 * Problem Statement: 3754. Concatenate Non-Zero Digits and Multiply by Sum I
 * You are given an integer n.
 * Form a new integer x by concatenating all the non-zero digits of n in their original order.
 * If there are no non-zero digits, x = 0.
 * Let sum be the sum of digits in x.
 * Return an integer representing the value of x * sum.
 *
 * Example 1:
 * Input: n = 10203004
 * Output: 12340
 * Explanation:
 * The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
 * The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
 * Therefore, the answer is x * sum = 1234 * 10 = 12340.
 * 
 * Example 2:
 * Input: n = 1000
 * Output: 1
 * Explanation:
 * The non-zero digit is 1, so x = 1 and sum = 1.
 * Therefore, the answer is x * sum = 1 * 1 = 1.
 * 
 * Constraints:
 * 0 <= n <= 109
*/

// My Solution:
// Time Complexity: O(log n) - We traverse through the digits of n once,
//                  which takes logarithmic time in terms of the number of digits.
// Space Complexity: O(1) - We use a constant amount of space for variables sum, x, and pos.
class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0, x = 0, pos = 1;

        while(n) {
            int last = n % 10;
            sum += last;

            if(last != 0) {
                x = (last * pos) + x;
                pos *= 10;
            }
            n /= 10;
        }

        return (1LL * sum * x);
    }
};
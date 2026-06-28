/*
 * Problem Statement: 1846. Maximum Element After Decreasing and Rearranging
 * You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it
 * satisfies these conditions:
 * # The value of the first element in arr must be 1.
 * # The absolute difference between any 2 adjacent elements must be less than or equal to 1.
 *   In other words, abs(arr[i] - arr[i - 1]) <= 1 for each i where 1 <= i < arr.length (0-indexed).
 *   abs(x) is the absolute value of x.
 * 
 * There are 2 types of operations that you can perform any number of times:
 * # Decrease the value of any element of arr to a smaller positive integer.
 * # Rearrange the elements of arr to be in any order.
 * Return the maximum possible value of an element in arr after performing the operations to satisfy the conditions.
 * 
 * Example 1:
 * Input: arr = [2,2,1,2,1]
 * Output: 2
 * Explanation: 
 * We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
 * The largest element in arr is 2.
 * 
 * Example 2:
 * Input: arr = [100,1,1000]
 * Output: 3
 * Explanation: 
 * One possible way to satisfy the conditions is by doing the following:
 * 1. Rearrange arr so it becomes [1,100,1000].
 * 2. Decrease the value of the second element to 2.
 * 3. Decrease the value of the third element to 3.
 * Now arr = [1,2,3], which satisfies the conditions.
 * The largest element in arr is 3.
 * 
 * Example 3:
 * Input: arr = [1,2,3,4,5]
 * Output: 5
 * Explanation: The array already satisfies the conditions, and the largest element is 5.
 * 
 * Constraints:
 * 1 <= arr.length <= 105
 * 1 <= arr[i] <= 109
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// My Solution:
// Sort the array first, then iterate through it to ensure the conditions are met.
// Main part here is we can decrease the value of any element to a smaller positive integer,
// so we can always make sure that the absolute difference between any 2 adjacent elements is
// less than or equal to 1 by decreasing the current element to be at most 1 greater than the previous element.
// The first element is set to 1 as required.
// Finally, we keep track of the maximum value encountered during this process and return it.
//
// Time Complexity: O(nlogn) - due to sorting the array
// Space Complexity: O(1) - no extra space used
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), max = 1;
        arr[0] = 1;

        for (int i = 1; i < n; i++) {
            if(!(abs(arr[i-1] - arr[i]) <= 1))
                arr[i] = arr[i-1] + 1;
            if(arr[i] > max) max = arr[i];
        }

        return max;
    }
};


// Optiomized Solution:
// Using counting sort.
// Time Complexity: O(n) - counting sort
// Space Complexity: O(n) - extra space used for counting array
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        // cnt[i] = how many numbers become value i
        // Any value > n can be treated as n because:
        // the maximum possible answer can never exceed n.
        vector<int> cnt(n + 1, 0);

        for (int num : arr)
            cnt[min(num, n)]++;

        /*
            Key idea:

            After rearranging and decrementing, we want:

                a[0] = 1
                a[i] - a[i-1] <= 1

            Let 'val' represent the largest value that can be achieved
            after processing all numbers <= current i.

            Suppose we are currently at value i.

            We already built numbers up to 'val'.

            cnt[i] numbers are available with value i.

            Using these cnt[i] numbers, we can extend the sequence by
            at most cnt[i] positions:

                new_max = val + cnt[i]

            However, the maximum value cannot exceed i because all these
            numbers originally belong to bucket i (or were capped to i).

            Therefore:

                val = min(i, val + cnt[i])

            This greedily computes the largest achievable value.
        */
        int val = 0;

        for (int i = 1; i <= n; i++) {
            val = min(i, val + cnt[i]);
        }

        // 'val' becomes the largest element in the final valid array.
        return val;
    }
};
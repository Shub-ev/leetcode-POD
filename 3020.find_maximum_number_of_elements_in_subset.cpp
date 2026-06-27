/*
 * Problem Statement: 3020. Find Maximum Number of Elements in Subset
 * You are given an array of positive integers nums.
 * You need to select a subset of nums which satisfies the following condition:
 * You can place the selected elements in a 0-indexed array such that it follows the pattern:
 * [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2).
 * For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
 * Return the maximum number of elements in a subset that satisfies these conditions.
 * 
 * Example 1:
 * Input: nums = [5,4,1,2,2]
 * Output: 3
 * Explanation: We can select the subset {4,2,2}, which can be placed in the array as [2,4,2] which follows
 * the pattern and 22 == 4. Hence the answer is 3.
 * 
 * Example 2:
 * Input: nums = [1,3,2,4]
 * Output: 1
 * Explanation: We can select the subset {1}, which can be placed in the array as [1] which follows
 * the pattern. Hence the answer is 1. Note that we could have also selected the subsets {2}, {3}, or {4},
 * there may be multiple subsets which provide the same answer. 
 * 
 * Constraints:
 * 2 <= nums.length <= 105
 * 1 <= nums[i] <= 109
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Solution:
// The solution uses a hash map to count the frequency of each number in the input array.
// It then iterates through the unique numbers in the hash map and checks for each number if it can be part of a valid sequence.
// The sequence is built by repeatedly squaring the number and checking if the squared value exists in the hash map with a frequency of at least 2.
// The length of the sequence is calculated based on how many times the number can be squared and still exist in the hash map.
// The maximum length of the sequence is updated accordingly, and the final answer is returned.

// Time Complexity: O(n log(max_num)), where n is the number of elements in the input array and max_num is the maximum number in the array. The log(max_num) factor comes from the repeated squaring of numbers.
// Space Complexity: O(n), where n is the number of unique elements in the input array, as we are using a hash map to store the frequency of each number.
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;

        for(int x: nums)
            mp[x]++;
        
        int ans = 1;

        if(mp.count(1)) {
            int cnt = mp[1];
            ans = max(ans, cnt%2 ? cnt : cnt-1);
        }

        for(auto &[num, f]: mp) {
            if(num == 1) continue;

            long long x = num;
            int len = 0;

            while(mp.count(x) && mp[x] >= 2) {
                len += 2;
                if(x > 1e9) break;
                x = x * x;
            }

            if(mp.count(x)) len++;
            else len--;

            ans = max(ans, len);
        }

        return ans;
    }
};
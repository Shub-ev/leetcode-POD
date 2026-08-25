/*
 * Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
 * A multiple of k is any positive integer divisible by k.
 * 
 * Example 1:
 * Input: nums = [8,2,3,4,6], k = 2
 * Output: 10
 * Explanation:
 * The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.
 *
 * Example 2:
 * Input: nums = [1,4,7,10,15], k = 5
 * Output: 5
 * Explanation:
 * The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.
 *
 * Constraints:
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 * 1 <= k <= 100
 */

#include <vector>
#include <unordered_map>
using namespace std;

// My Solution:
// Time Complexity: O(n) where n is the length of nums
// Space Complexity: O(1) since the size of the array is fixed
// I will create an array of size 1001 to store the count of each number in nums.
// Then, I will iterate through the multiples of k starting from k and check if they are present in the array.
// The first multiple that is not present will be returned as the result.
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int arr[1001] = {0};
        for (int num: nums) {
            arr[num]++;
        }

        int mul = 1;
        int res = k;
        while(true) {
            if(arr[(mul * k)] != 0)
                mul++;
            else {
                res = mul * k;
                break;
            }
        }

        return res;
    }
};


// Better approach:
// Time Complexity: O(n) where n is the length of nums
// Space Complexity: O(n) where n is the length of nums
// I will use a hash map to store the multiples of k that are present in nums.
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num: nums) {
            if ( num % k == 0 ) {
                mp[ num / k ] = true;
            }
        }

        int i = 1;
        while(true) {
            if(!mp[i]) {
                return i * k;
            }
            i++;
        }
    }
};
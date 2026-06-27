/*
 * Problem Statement: 3737. Count Subarrays with Majority Element I
 * You are given an integer array nums and an integer target.
 * Return the number of subarrays of nums in which target is the majority element.
 * The majority element of a subarray is the element that appears strictly more than half of the times
 * in that subarray.
 * 
 * Example 1:
 * Input: nums = [1,2,2,3], target = 2
 * Output: 5
 * Explanation:
 * Valid subarrays with target = 2 as the majority element:
 * nums[1..1] = [2]
 * nums[2..2] = [2]
 * nums[1..2] = [2,2]
 * nums[0..2] = [1,2,2]
 * nums[1..3] = [2,2,3]
 * So there are 5 such subarrays.
 * 
 * Example 2:
 * Input: nums = [1,1,1,1], target = 1
 * Output: 10
 * Explanation:
 * ​​​​​​​All 10 subarrays have 1 as the majority element.
 * 
 * Example 3:
 * Input: nums = [1,2,3], target = 4
 * Output: 0
 * Explanation:
 * target = 4 does not appear in nums at all.
 * Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.
 * 
 * Constraints:
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10​​​​​​​9
 * 1 <= target <= 109
 */

#include <iostream>
#include <vector>
using namespace std;

// First approach: Prefix Sum Enumeration
// We use a prefix sum array to efficiently calculate the number of target elements in any subarray.
// For each subarray, if the difference in prefix sums is positive, it means the target is the majority element.
//
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int res = 0, n = nums.size();
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + (nums[i] == target ? 1 : -1);

        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                if(prefix[r+1] - prefix[l] > 0) res++;
            }
        }

        return res;
    }
};

#include <algorithm>

// Fenwick Tree (Binary Indexed Tree) approach.
// 1. Transform the array into a prefix sum array where we add +1 for the target and -1 for non-target elements.
// 2. Use coordinate compression to map the prefix sums to a smaller range.
// 3. Use a Fenwick Tree to efficiently count the number of previous prefix sums that are strictly smaller than the current prefix sum.
//    This allows us to count the number of valid subarrays in O(n log n) time complexity.
class FenwickTree {
    private:
        vector<int> tree;
        int n;

    public:
        // Constructor to initialize the Fenwick Tree with size n
        FenwickTree(int n) {
            this->n = n;
            tree.resize(n + 1, 0);
        }

        // Update the Fenwick Tree at a specific index with a given data value
        void update(int index, int data) {
            while(index <= n) {
                tree[index] += data;
                index += index & (-index);
            }
        }

        // Query the Fenwick Tree for the sum of elements from index 1 to the given index
        int query(int index) {
            int sum = 0;
            while(index > 0) {
                sum += tree[index];
                index -= index & (-index);
            }
            return sum;
        }
};

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        /*
        --------------------------------------------------------
        IDEA:
        --------------------------------------------------------
        We need to count subarrays where 'target' appears
        MORE than half of the subarray length.
        Instead of counting frequencies directly, transform:

            target     -> +1
            non-target -> -1

        Example:
            nums = [1,2,2,1]
            target = 2

            transformed:
            [-1,+1,+1,-1]

        For any subarray:
            sum > 0

        means
            (#target) > (#non-target)

        which is exactly the condition:
            target is majority element
        */

        /*
        --------------------------------------------------------
        STEP 1: Build Prefix Sum Array
        --------------------------------------------------------
        prefix[i] = transformed sum of first i elements
        prefix[0] = 0

        Example:
            transformed = [-1,+1,+1,-1]
            prefix:
            [0,-1,0,1,0]
        Why?

        Subarray sum from l to r:
            prefix[r+1] - prefix[l]
        */
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] +
                (nums[i] == target ? 1 : -1);
        }

        /*
        --------------------------------------------------------
        STEP 2: Coordinate Compression
        --------------------------------------------------------
        Prefix sums may be negative.
        Example:
            [-100000, -99999, ..., 100000]

        Fenwick Tree cannot directly use such values
        as indices.
        Therefore we compress them.

        Example:
            prefix = [0,-1,0,1,0]

            unique sorted values:
            [-1,0,1]

            compressed mapping:
            -1 -> 1
             0 -> 2
             1 -> 3
        Now every prefix sum becomes a small positive index.
        */

        vector<int> values = prefix;
        // Sort all prefix sums
        sort(values.begin(), values.end());

        // Remove duplicates
        values.erase(
            unique(values.begin(), values.end()),
            values.end()
        );

        /*
        Fenwick Tree stores frequencies of prefix sums
        encountered so far.
        Size = number of unique prefix sums.
        */
        FenwickTree bit(values.size());

        long long answer = 0;

        /*
        --------------------------------------------------------
        STEP 3: Count Valid Prefix Pairs
        --------------------------------------------------------
        We process prefix sums from left to right.
        Let:
            currentPrefix = prefix[j]
        We want all previous prefix sums:
            prefix[i]

        such that:
            prefix[j] - prefix[i] > 0

        Rearranging:
            prefix[i] < prefix[j]

        Therefore:
        For every current prefix sum, count how many previous prefix sums
        are STRICTLY SMALLER than it.
        Each such pair (i,j) corresponds to one valid majority subarray.
        */

        for (int currentPrefix : prefix) {
            /*
            Find compressed index (rank).
            Example:
                values = [-1,0,1]
                currentPrefix = 0
                rank = 2
            */
            int rank =
                lower_bound(
                    values.begin(),
                    values.end(),
                    currentPrefix
                ) - values.begin() + 1;

            /*
            Query Fenwick Tree:
            Count all previously seen prefix sums
            having rank < current rank.

            rank -1 means:
                strictly smaller values only

            This gives the number of valid starting
            positions for subarrays ending here.
            */
            answer += bit.query(rank - 1);

            /*
            Mark current prefix sum as seen.
            Frequency(rank) += 1
            */
            bit.update(rank, 1);
        }
        
        /*
        Total valid subarrays.
        */
        return answer;
    }
};
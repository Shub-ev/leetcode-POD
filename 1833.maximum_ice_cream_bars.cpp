/*
 * Problem Statement: 
 * It is a sweltering summer day, and a boy wants to buy some ice cream bars.
 * At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
 *  Note: The boy can buy the ice cream bars in any order.
 * Return the maximum number of ice cream bars the boy can buy with coins coins.
 * You must solve the problem by counting sort.
 * 
 * Example 1:
 * Input: costs = [1,3,2,4,1], coins = 7
 * Output: 4
 * Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
 * 
 * Example 2:
 * Input: costs = [10,6,8,7,7,8], coins = 5
 * Output: 0
 * Explanation: The boy cannot afford any of the ice cream bars.
 * 
 * Example 3:
 * Input: costs = [1,6,3,1,2,5], coins = 20
 * Output: 6
 * Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
 * 
 * Constraints:
 * costs.length == n
 * 1 <= n <= 105
 * 1 <= costs[i] <= 105
 * 1 <= coins <= 108
 */

#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(nlogn) due to sorting the costs array.
// Space Complexity: O(1) as we are sorting the costs array in place and using only a
// constant amount of extra space for the variables.

// But leetcode wants us to solve the problem by "counting sort", which has a time complexity of
// O(n + k) where k is the range of the input values (in this case, the maximum cost of an ice cream bar).
// The space complexity of counting sort is O(k) due to the count array used for sorting.
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int ite = 0, ans = 0;
        while((ite < costs.size()) && (coins >= costs[ite])) {
            coins -= costs[ite];
            ans++;
            ite++;
        }

        return ans;
    }
};


// Counting sort solution:
// Time Complexity: O(n + k) where n is the number of ice cream bars and k is the maximum cost of an ice cream bar (100000 in this case).
// Space Complexity: O(k) due to the frequency array used for counting the occurrences of each
// (explain solution) -> We create a frequency array `freq` of size 100001 to count the occurrences of each cost.
// We then iterate through the costs and populate the frequency array.
// Next, we iterate through the possible prices (from 1 to 100000) and for each price,
// we determine how many ice cream bars we can buy with the remaining coins.
// We update the coins and the answer accordingly until we can no longer afford any more ice cream bars.
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001, 0);
        int ans = 0;

        for(int cost: costs)
            freq[cost]++;

        for(int price = 1; price < 100001; price++) {
            if(freq[price] == 0) continue;

            int canBuy = min(freq[price], coins / price);
            coins -= (canBuy * price);
            ans += canBuy;
        }

        return ans;
    }
};
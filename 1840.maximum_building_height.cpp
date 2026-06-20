/*
 * Problem: 1840. Maximum Building Height
 * 
 * You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
 * However, there are city restrictions on the heights of the new buildings:
 * 1. The height of each building must be a non-negative integer.
 * 2. The height of the first building must be 0.
 * 3. The height difference between any two adjacent buildings cannot exceed 1.
 * 4. Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
 *
 * It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
 *
 * Return the maximum possible height of the tallest building.
 */ 

 

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1,0});
        rest.push_back({n, n - 1});

        sort(rest.begin(), rest.end());
        int m = rest.size();

        int ans = 0;

        // Left -> Right pass
        for(int i = 1; i < m; i++) {
            int dist = rest[i][0] - rest[i-1][0];
            rest[i][1] = min(rest[i][1], rest[i-1][1] + dist);
        }

        // Left -> Right pass
        for(int i = m - 2; i >= 0; i--) {
            int dist = rest[i+1][0] - rest[i][0];
            rest[i][1] = min(rest[i][1], rest[i+1][1] + dist);
        }

        // Find maximum peak between every adjacent restriction pair
        for(int i = 1; i < m; i++) { 
            int dist = rest[i][0] - rest[i-1][0];
            int h1 = rest[i-1][1];
            int h2 = rest[i][1];

            int peak = (h1 + h2 + dist)/2;
            ans = max(ans, peak);
        }

        return ans;
    }
};
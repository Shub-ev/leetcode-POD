/*
Given an m x n binary matrix mat, return the number of special positions in mat.
A position (i, j) is called special if mat[i][j] == 1 and all other elements in
row i and column j are 0 (rows and columns are 0-indexed).

Example 1:
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.

Example 2:
Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions. 

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res = 0;
        // number of rows
        int m = mat.size();
        // number of cols
        int n = mat[0].size();

        // iterate each row
        for (int i = 0; i < m; i++) {
            // check if row has only one "1" -> check row
            int ones = 0;
            int oneIdx = 0;     // we need index of 1
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) { 
                    ones++;
                    oneIdx = j;
                }
                if(ones > 1) break;         // early break to avoid unnecessary checks
            }

            // if we have only one "1" in row then only we check col
            if(ones == 1) {
                ones = 0;
                // check column for number of 1's
                for(int k = 0; k < m; k++) {
                    if(mat[k][oneIdx] == 1) {
                        ones++;
                    }
                    if(ones > 1) break;     // early break to avoid unnecessary checks
                }

                // if col also have only one 1 then increase 1
                if(ones == 1) res++;
            }
        }
        return res;
    }
};


// Also another solution -> not optimal but cleaner
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);

        // Here we precount the number of 1's in rows and cols
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }

        int ans = 0;
        // Then iterate matrix again to find the special positions
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    ans++;

        return ans;
    }
};

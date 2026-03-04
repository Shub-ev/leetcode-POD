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

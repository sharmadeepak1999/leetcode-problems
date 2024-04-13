class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (n + 1, {0, 0, 0, INT_MAX, INT_MAX}));
        for(int c = 0; c < n; c++) {
            for(int r = m - 1; r >= 0; r--) {
                dp[r][c][1] = matrix[r][c] == '1' ? dp[r + 1][c][1] + 1 : 0;
            }
        }
        
        for(int c = 0; c < n; c++) {
            for(int r = 0; r < m; r++) {
                if(r == 0) dp[r][c][2] = matrix[r][c] == '1';
                else dp[r][c][2] = matrix[r][c] == '1' ? dp[r - 1][c][2] + 1: 0;
            }
        }
        for(int r = 0; r < m; r++) {
            for(int c = n - 1; c >= 0; c--) {
                dp[r][c][0] = matrix[r][c] == '1' ? dp[r][c + 1][0] + 1 : 0;
                dp[r][c][3] = matrix[r][c] == '1' ? min(dp[r][c + 1][3], dp[r][c][1]) : INT_MAX;  
                dp[r][c][4] = matrix[r][c] == '1' ? min(dp[r][c + 1][4], dp[r][c][2]) : INT_MAX;  

            }
        }
        int maxi = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] != '0') {
                    int curr = dp[i][j][0] * (dp[i][j][3] + dp[i][j][4] - 1);
                    maxi = max(maxi, curr);
                }
            }
        }
        
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << dp[i][j][0] << ' ' << dp[i][j][1] << ' ' << dp[i][j][2] << ' ' << dp[i][j][3] << ' ' << dp[i][j][4] << "; ";
        //     }
        //     cout << endl;
        // }
        return maxi;
    }
};
// [

    
// ["1","1","1","1","1","1","1","1"],
// ["1","1","1","1","1","1","1","0"],
// ["1","1","1","1","1","1","1","0"],
// ["1","1","1","1","1","0","0","0"],
// ["0","1","1","1","1","0","0","0"]
 

// ]
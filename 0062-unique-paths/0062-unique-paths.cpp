class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int left = 0, up = 0;
                    
                    if(j > 0) left = dp[i][j - 1];
                    if(i > 0) up = dp[i - 1][j];
                    dp[i][j] = left + up;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
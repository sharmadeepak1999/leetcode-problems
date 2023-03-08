class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int ldiag = 1e9, rdiag = 1e9, down = 1e9;
                
                if(j > 0) ldiag = dp[i + 1][j - 1];
                down = dp[i + 1][j];
                if(j < n - 1) rdiag = dp[i + 1][j + 1];
                dp[i][j] = matrix[i][j] + min(min(ldiag, rdiag), down);
            }
        }
        for(int i = 0; i < n; i++) {
            mini = min(mini, dp[0][i]);
        }
        return mini;
    }
};
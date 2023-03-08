class Solution {
public:
    int helper(int m, int n, vector<vector<int>> &dp) {
        if(m < 0 || n < 0) return 0;
        if(m == 0 && n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int left = helper(m, n - 1, dp);
        int up = helper(m - 1, n, dp);
        return dp[m][n] = left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp);
    }
};
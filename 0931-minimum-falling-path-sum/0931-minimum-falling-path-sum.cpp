class Solution {
public:
    int helper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int n, int i, int j) {
        if(j < 0 || j > n) return 1e9;
        if(i == n) return matrix[i][j];
        if(dp[i][j] != 1e9) return dp[i][j];
        int ldiag = helper(matrix, dp, n, i + 1, j - 1);
        int down = helper(matrix, dp, n, i + 1, j);
        int rdiag = helper(matrix, dp, n, i + 1, j + 1);
        
        return dp[i][j] = matrix[i][j] + min(min(ldiag, rdiag), down);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) {
            mini = min(mini, helper(matrix, dp, n - 1, 0, i));
        }
        return mini;
    }
};
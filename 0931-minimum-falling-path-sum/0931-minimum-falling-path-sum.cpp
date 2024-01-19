class Solution {
    int helper(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp) {
        if(j < 0 || j >= matrix[0].size()) return INT_MAX;
        if(i == matrix.size() - 1) return matrix[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        return dp[i][j] = matrix[i][j] + min(helper(matrix, i + 1, j, dp), min(helper(matrix, i + 1, j - 1, dp), helper(matrix, i + 1, j + 1, dp)));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            mini = min(mini, helper(matrix, 0, i, dp));
        }
        return mini;
    }
};
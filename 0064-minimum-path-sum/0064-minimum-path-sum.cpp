class Solution {
public:
    int helper(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j) {
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int left = grid[i][j] + helper(grid, dp, i, j -  1);
        int up = grid[i][j] + helper(grid, dp, i - 1, j);
        return dp[i][j] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, dp, m - 1, n - 1);
    }
};
class Solution {
public:
    int helper(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j) {
        if(i < 0 || j < 0 || grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int left = helper(grid, dp, i, j - 1);
        int up = helper(grid, dp, i - 1, j);
        return dp[i][j] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(obstacleGrid, dp, m - 1, n - 1);
    }
};
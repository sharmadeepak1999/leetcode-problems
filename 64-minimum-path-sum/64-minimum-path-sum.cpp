class Solution {
public:
    /*
    int helper(vector<vector<int>>& grid, int m, int n) {
        if(m == 0 && n == 0) return grid[0][0];
        if(m < 0 || n < 0) return INT_MAX;
        return grid[m][n] + min(helper(grid, m - 1, n), helper(grid, m, n - 1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        // We will use top down approach, we will use the current cell and add to it the minimum of the result from the recursion call to the left and upper cell, when we react the (0, 0) cell, we return the cell value only, else if we reach out of boundary then we return infinity because we will choose the min of the recursion calls in the backtrack step. 
        return helper(grid, grid.size() - 1, grid[0].size() - 1);
    }
    */
    
    int helper(vector<vector<int>>& grid, vector<vector<int>> &dp, int m, int n) {
        if(m == 0 && n == 0) return grid[0][0];
        if(m < 0 || n < 0) return INT_MAX;
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = grid[m][n] + min(helper(grid, dp, m - 1, n), helper(grid, dp, m, n - 1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        // We will use memoization to the previous process.
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, dp, grid.size() - 1, grid[0].size() - 1);
    }
};
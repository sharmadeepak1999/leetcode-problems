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
    
    
    /*
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
    */
    
    /*
    int minPathSum(vector<vector<int>>& grid) {
        // We will use the tabulation process. this would be the bottom up appraoch in which we simply convert the recursion to iteration. 
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[0][0] = grid[0][0];
                else {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    
                    if(i > 0) up = dp[i - 1][j];
                    if(j > 0) left = dp[i][j - 1];
                    
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    */
    
    
    int minPathSum(vector<vector<int>>& grid) {
        // We can space optimize the tabulation method, since it only uses the current row's left and previous row, we can just maintain a prev row array, instead of a full dp array.
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        
        for(int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) curr[0] = grid[0][0];
                else {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j - 1];
                    
                    curr[j] = grid[i][j] + min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};
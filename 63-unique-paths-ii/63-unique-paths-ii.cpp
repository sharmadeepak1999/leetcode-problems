class Solution {
public:
    /*
    int helper(vector<vector<int>>& grid, int m, int n) {
        if(m < 0 || n < 0) return 0;
        if(grid[m][n] == 1) return 0;
        if(m == 0 && n == 0) return 1;
        return helper(grid, m - 1, n) + helper(grid, m, n - 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Simply traverse from the backward, and go to the base case of (0, 0) when this happens return 1, else if we find blocker anytime return 0, or when the index go out of bound return 0, else return the sum of recursion on the upper and the left index. 
        return helper(obstacleGrid, obstacleGrid.size() - 1, obstacleGrid[0].size() - 1);
    }
    */
    
   
    /*
    int helper(vector<vector<int>>& grid, int m, int n) {
        if(m < 0 || n < 0) return 0;
        if(grid[m][n] == 1) return 0;
        if(m == 0 && n == 0) return 1;
        return helper(grid, m - 1, n) + helper(grid, m, n - 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Using memoization technique
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        return helper(obstacleGrid, m - 1, n - 1);
    }
    */
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Using memoization technique
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
     
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                
                if(i == 0 && j == 0) {
                    dp[0][0] = 1;
                    continue;
                }
                
                int up = 0;
                int left = 0; 
                
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];
                
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};
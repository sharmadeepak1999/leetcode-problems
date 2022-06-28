class Solution {
public:
    /*
    int helper(vector<vector<int>>& grid, int m, int n, int i, int j1, int j2) {
        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return -1e8;
        }
        if(i == m - 1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        int maxCherry = -1e8;
        for(int d1 = -1; d1 <= 1; d1++) {
            for(int d2 = -1; d2 <= 1; d2++) {
                int currCherry = 0;
                if(j1 == j2) {
                    currCherry = helper(grid, m, n, i + 1, j1 + d1, j2 + d2);
                    maxCherry = max(maxCherry, grid[i][j1] + currCherry);
                }
                else {
                    currCherry = helper(grid, m, n, i + 1, j1 + d1, j2 + d2);
                    maxCherry = max(maxCherry, grid[i][j1] + grid[i][j2]  + currCherry);
                }
            }
        }
        return maxCherry; 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        // We will start from the first row, and traverse the matrix simultaneously for both the robots, if anyone of it goes out of boundary return with a large negative no. else if we reach the last row, then check if both the robot landed on the same cell, then return only one time the value of the cell, if both land on different cell then return their own cell values, else if they are not in the last row, then we will call recursion for all the possibility of movement for both the robots, for each move of the first robot, the second robot can move 3 different direction, so in all there would be 9 combination of recursion calls, the maximum of the each recursion call will be returned as the answer with the addition of the current cell value, note if both the robot are on same cell, then add only one time the cell value, else add both robot cell value. this will give tle. we need to optimize. 
        int m = grid.size();
        int n = grid[0].size();
        return helper(grid, m, n, 0, 0, n - 1);
    }
    */
    
    /*
    int helper(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n, int i, int j1, int j2) {
        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return -1e8;
        }
        if(i == m - 1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxCherry = -1e8;
        for(int d1 = -1; d1 <= 1; d1++) {
            for(int d2 = -1; d2 <= 1; d2++) {
                int currCherry = 0;
                if(j1 == j2) {
                    currCherry = helper(grid, dp, m, n, i + 1, j1 + d1, j2 + d2);
                    maxCherry = max(maxCherry, grid[i][j1] + currCherry);
                }
                else {
                    currCherry = helper(grid, dp, m, n, i + 1, j1 + d1, j2 + d2);
                    maxCherry = max(maxCherry, grid[i][j1] + grid[i][j2]  + currCherry);
                }
            }
        }
        return dp[i][j1][j2] = maxCherry; 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        // We will use memoization using 3d DP.
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(grid, dp, m, n, 0, 0, n - 1);
    }
    */
    
    int helper(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n, int i, int j1, int j2) {
        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return -1e8;
        }
        if(i == m - 1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxCherry = -1e8;
        for(int d1 = -1; d1 <= 1; d1++) {
            for(int d2 = -1; d2 <= 1; d2++) {
                int currCherry = 0;
                if(j1 == j2) {
                    currCherry = helper(grid, dp, m, n, i + 1, j1 + d1, j2 + d2);
                    maxCherry = max(maxCherry, grid[i][j1] + currCherry);
                }
                else {
                    currCherry = helper(grid, dp, m, n, i + 1, j1 + d1, j2 + d2);
                    maxCherry = max(maxCherry, grid[i][j1] + grid[i][j2]  + currCherry);
                }
            }
        }
        return dp[i][j1][j2] = maxCherry; 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        // We will use tabulation method.
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        
        for(int j1 = 0; j1 < n; j1++) {
            for(int j2 = 0; j2 < n; j2++) {
                if(j1 == j2) dp[m - 1][j1][j2] = grid[m - 1][j1];
                else dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }
        
        for(int i = m - 2; i >= 0; i--) {
            for(int j1 = 0; j1 < n; j1++) {
                for(int j2 = 0; j2 < n; j2++) {
                    int maxCherry = -1e8;
                    for(int d1 = -1; d1 <= 1; d1++) {
                        for(int d2 = -1; d2 <= 1; d2++) {
                            int currCherry = 0;
                            if(j1 == j2) {
                               currCherry = grid[i][j1];
                            }
                            else {
                                currCherry = grid[i][j1] + grid[i][j2];
                            }
                            if ((j1 + d1 < 0 || j1 + d1 >= n) ||
                              (j2 + d2 < 0 || j2 + d2 >= n))

                              currCherry += -1e9;
                            else
                              currCherry += dp[i + 1][j1 + d1][j2 + d2];
                            maxCherry = max(maxCherry, currCherry);
                        }
                    }
                    dp[i][j1][j2] = maxCherry;
                }
            }    
        }
        return dp[0][0][n - 1];
    }
};
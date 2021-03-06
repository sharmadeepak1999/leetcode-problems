class Solution {
public:
    /*
    int helper(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if(i == m - 1 && j == n - 1) {
            return 1;
        }
        
        if(i >= m || j >= n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = helper(i + 1, j, m, n, dp) + helper(i, j + 1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        // Using the method of recursion for counting, return 0 or 1 depending on the base case. we will also use a dp to store overlapping sub problems value. this is the bottom approach. 
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(0, 0, m, n, dp);
    }
    */
    
    /*
    int helper(int m, int n, vector<vector<int>>& dp) {
        if(m == 0 && n == 0) {
            return 1;
        }
        
        if(m < 0 || n < 0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
    }
    int uniquePaths(int m, int n) {
        // Using the method of recursion for counting, return 0 or 1 depending on the base case. we will also use a dp to store overlapping sub problems value. this is top down approach.
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(m - 1, n - 1, dp);
    }
    */

    /*
    int uniquePaths(int m, int n) {
        // Tabulation method, bottom Up approach. 
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for(int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    */
    
    /*
    int uniquePaths(int m, int n) {
        // Tabulation method, bottom Up approach. 
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for(int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    */
    
    int uniquePaths(int m, int n) {
        // Tabulation another method, bottom Up approach. 
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[0][0] = 1;
                    continue;
                }
                int up = 0, down = 0;
                if(i >= 1) up = dp[i - 1][j];
                if(j >= 1) down = dp[i][j - 1];
                
                dp[i][j] = up + down;
            }
        }
        return dp[m - 1][n - 1];
    }
    
};
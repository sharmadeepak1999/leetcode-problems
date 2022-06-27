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
};
class Solution {
public:
    /*
    int helper(vector<vector<int>>& matrix, int m, int n) {
        if(n < 0 || n >= matrix.size()) return INT_MAX;
        
        if(m == matrix.size() - 1) {
            return matrix[m][n]; 
        }        
        int d = helper(matrix, m + 1, n);
        int ldg = helper(matrix, m + 1, n - 1);
        int rdg = helper(matrix, m + 1, n + 1);
        return matrix[m][n] + min(d, min(ldg, rdg));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Bottom up appraoch with recursion.
        int m = matrix.size();
        int n = matrix[0].size();
        
        int minPath = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            minPath = min(minPath, helper(matrix, 0, i));
        }
        return minPath;
    }
    */
    
    /*
    int helper(vector<vector<int>>& matrix, int m, int n) {
        if(n < 0 || n >= matrix.size()) return INT_MAX;
        
        if(m == 0) {
            return matrix[m][n]; 
        }        
        int u = helper(matrix, m - 1, n);
        int ldg = helper(matrix, m - 1, n - 1);
        int rdg = helper(matrix, m - 1, n + 1);
        return matrix[m][n] + min(u, min(ldg, rdg));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Top down appraoch with recursion. we will loop through every element in the last row and call recursion for it, in the recursive function we will check if we have react the first row, then return the current element, else we will check if we are out of index, then we will return infinity, else we will call recursion for the current, current - 1, current + 1 indexes of the upper row and find min of them and add to the current element and return. this will give tle.
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int minPath = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            minPath = min(minPath, helper(matrix, m - 1, i));
        }
        return minPath;
    }
    */
    
    /*
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int m, int n) {
        if(n < 0 || n >= matrix.size()) return INT_MAX;
        
        if(m == 0) {
            return matrix[m][n]; 
        }
        if(dp[m][n] != INT_MAX) return dp[m][n];
        int u = helper(matrix, dp, m - 1, n);
        int ldg = helper(matrix, dp, m - 1, n - 1);
        int rdg = helper(matrix, dp, m - 1, n + 1);
        return dp[m][n] = matrix[m][n] + min(u, min(ldg, rdg));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // We will use memoization to improve time compx.
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        int minPath = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            minPath = min(minPath, helper(matrix, dp, m - 1, i));
        }
        return minPath;
    }
    */
    
    /*
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // We will use tabulation to improve space compx.
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < n; i++) {
            dp[m - 1][i] = matrix[m - 1][i];
        }
        
        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j < n; j++) {
                int d = dp[i + 1][j];
                int ldg = j > 0 ? dp[i + 1][j - 1] : INT_MAX;
                int rdg = j < n - 1 ? dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(d, min(ldg, rdg));
            }
        }
        
        int minPath = INT_MAX;
        for(int i = 0; i < n; i++) {
            minPath = min(minPath, dp[0][i]);
        }
        return minPath;
    }
    */
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // We will space optimize it now.
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> front(n, 0);
        
        for(int i = 0; i < n; i++) {
            front[i] = matrix[m - 1][i];
        }
        
        for(int i = m - 2; i >= 0; i--){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++) {
                int d = front[j];
                int ldg = j > 0 ? front[j - 1] : INT_MAX;
                int rdg = j < n - 1 ? front[j + 1] : INT_MAX;
                curr[j] = matrix[i][j] + min(d, min(ldg, rdg));
            }
            front = curr;
        }
        
        int minPath = INT_MAX;
        for(int i = 0; i < n; i++) {
            minPath = min(minPath, front[i]);
        }
        return minPath;
    }
    
};
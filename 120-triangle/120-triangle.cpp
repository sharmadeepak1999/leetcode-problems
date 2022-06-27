class Solution {
public:
    /*
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int m, int n) {
        if(m == triangle.size() - 1) {
            return triangle[m][n];
        }
        
        if(dp[m][n] != INT_MAX) return dp[m][n];
        
        return dp[m][n] = triangle[m][n] + min(helper(triangle, dp, m + 1, n), helper(triangle, dp, m + 1, n + 1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // We will use the bottom up approach, we will start from the beginning and will call recursion on the curr index, and curr index + 1 on the next row, the min of both the recursion call will be added to the curr element value, that would be the min path sum for the triangle, base case would be when the last row is reached. memoization is done to optimize runtime.
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), INT_MAX));
        return helper(triangle, dp, 0, 0);
    }
    */
    
    /*
    int minimumTotal(vector<vector<int>>& triangle) {
        // We will use tabulation now
        vector<vector<int>> dp(triangle.size() + 1, vector<int>(triangle[triangle.size() - 1].size() + 1, 0));
        
        for(int i = triangle.size() - 1; i >= 0; i--) {
            int n = triangle[i].size();
            for(int j = n - 1; j >= 0; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
    */
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        // We will space optimize now
        
        vector<int> next(triangle.size() + 1, 0);
        
        for(int i = triangle.size() - 1; i >= 0; i--) {
            int n = triangle[i].size();
            vector<int> curr(n + 1, 0);
            for(int j = n - 1; j >= 0; j--) {
                curr[j] = triangle[i][j] + min(next[j], next[j + 1]);
            }
            next = curr;
        }
        return next[0];
    }
};
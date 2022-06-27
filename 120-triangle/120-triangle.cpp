class Solution {
public:
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int m, int n) {
        if(m == triangle.size() - 1) {
            return triangle[m][n];
        }
        
        if(dp[m][n] != INT_MAX) return dp[m][n];
        
        return dp[m][n] = triangle[m][n] + min(helper(triangle, dp, m + 1, n), helper(triangle, dp, m + 1, n + 1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), INT_MAX));
        return helper(triangle, dp, 0, 0);
    }
};
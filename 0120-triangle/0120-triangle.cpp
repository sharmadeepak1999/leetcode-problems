class Solution {
public:
    int helper(vector<vector<int>> &triangle, vector<vector<int>> &dp, int i, int j) {
        if(i == triangle.size() - 1) {
            return triangle[triangle.size() - 1][j];
        }
        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        int down = helper(triangle, dp, i + 1, j);
        int diag = helper(triangle, dp, i + 1, j + 1);
        
        return dp[i][j] = triangle[i][j] + min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), INT_MAX));
        return helper(triangle, dp, 0, 0);
    }
};
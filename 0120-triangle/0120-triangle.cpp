class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(triangle[m - 1].size(), INT_MAX));
        for(int i = 0; i < triangle[m - 1].size(); i++) {
            dp[m - 1][i] = triangle[m - 1][i];
        }
        
        for(int i = m - 2; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];
                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }
        return dp[0][0];
    }
};
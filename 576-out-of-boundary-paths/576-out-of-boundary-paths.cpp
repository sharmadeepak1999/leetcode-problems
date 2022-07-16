class Solution {
public:
    int mod = 1000000007;
    long helper(vector<vector<vector<int>>> &dp, int m, int n, int i, int j, int maxMove) {
        if(i >= m || j >= n || j < 0 || i < 0) return 1;
        if(maxMove <= 0) return 0;
        
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        
        return dp[i][j][maxMove] = ((helper(dp, m, n, i + 1, j, maxMove - 1) % mod) + (helper(dp, m, n, i, j + 1, maxMove - 1) % mod) + (helper(dp, m, n, i - 1, j, maxMove - 1) % mod) + (helper(dp, m, n, i, j - 1, maxMove - 1) % mod)) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return helper(dp, m, n, startRow, startColumn, maxMove);   
    }
};
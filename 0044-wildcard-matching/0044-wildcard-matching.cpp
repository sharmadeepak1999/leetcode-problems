class Solution {
public:
    bool helper(string s, string p, vector<vector<int>> &dp, int i, int j) {
        if(i == 0 && j == 0) return true;
        if(j == 0 && i > 0) return false;
        if(i == 0 && j > 0) {
            for(int c = 1; c <= j; c++) {
                if(p[c - 1] != '*') return false;
            }    
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == p[j - 1] || p[j - 1] == '?') return dp[i][j] = helper(s, p, dp, i - 1, j - 1);
        if(p[j - 1] == '*') return dp[i][j] = helper(s, p, dp, i - 1, j) || helper(s, p, dp, i, j - 1);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for(int j = 1; j <= n; j++) {
            dp[0][j] = 1;
            for(int c = 1; c <= j; c++) {
                if(p[c - 1] != '*') {
                    dp[0][j] = 0;
                    break;
                }
            }
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*') dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                else dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};
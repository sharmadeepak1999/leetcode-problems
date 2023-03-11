class Solution {
public:
    int helper(string s, string t, vector<vector<int>> &dp, int i, int j) {
        if(j == 0) return i;
        if(i == 0) return j;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1]) {
            return dp[i][j] = helper(s, t, dp, i - 1, j - 1);
        } else {
            return dp[i][j] = min(1 + helper(s, t, dp, i - 1, j - 1), min(1 + helper(s, t, dp, i - 1, j), 1 + helper(s, t, dp, i, j - 1)));
        }
    }
    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[m][n];
    }
};
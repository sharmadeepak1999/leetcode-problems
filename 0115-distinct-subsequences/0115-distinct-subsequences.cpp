class Solution {
public:
    int helper(string s, string t, vector<vector<int>> &dp, int i, int j) {
        if(j <= 0) return 1;
        if(i <= 0) {
            if(j <= 0) return 1;
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1]) {
            return dp[i][j] = helper(s, t, dp, i - 1, j - 1) + helper(s, t, dp, i - 1, j);
        } else return dp[i][j] = helper(s, t, dp, i - 1, j);
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(s, t, dp, m, n);
    }
};
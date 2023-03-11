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
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, dp, m, n);
    }
};
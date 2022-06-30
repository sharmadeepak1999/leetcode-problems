class Solution {
public:
    /*
    int helper(string s, string t, vector<vector<int>> &dp, int i, int j) {
        if(j < 0) return 1;
        if(i < 0) return 0;
        
        // Alternate base case;
        // if(i == 0) {
        //     return j == 0 && s[0] == t[0];
        // }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = helper(s, t, dp, i - 1, j - 1) + helper(s, t, dp, i - 1, j);
        return dp[i][j] = helper(s, t, dp, i - 1, j);
    }
    int numDistinct(string s, string t) {
        // Using memoization
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return helper(s, t, dp, s.length() - 1, t.length() - 1);
    }
    */
    
    int numDistinct(string s, string t) {
        // Using tabulation technique, we need to use 1 based indexing to avoid negative indexes in the dp array. 
        // We will use double just to avoid run time error, and type case it to int when returning.
        vector<vector<double>> dp(s.length() + 1, vector<double>(t.length() + 1, 0));
        
        for(int i = 0; i <= s.length(); i++) {
            dp[i][0] = 1;
        }
        // starting from 1 in order to avoid rewriting the value from the prev loop.
        for(int j = 1; j <= t.length(); j++) {
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= t.length(); j++) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return (int) dp[s.length()][t.length()];
    }
};
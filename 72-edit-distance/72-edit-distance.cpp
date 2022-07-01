class Solution {
public:
    /*
    int helper(string word1, string word2,  vector<vector<int>> &dp, int i, int j) {
        if(j == 0) return i;
        if(i == 0) return j;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(word1[i - 1] == word2[j - 1]) {
            return dp[i][j] = helper(word1, word2, dp, i - 1, j - 1);
        } else {
            int del = 1 + helper(word1, word2, dp, i - 1, j);
            int repl = 1 + helper(word1, word2, dp, i - 1, j - 1);
            int insert = 1 + helper(word1, word2, dp, i, j - 1);
            return dp[i][j] = min(del, min(repl, insert));
        }
    }
    int minDistance(string word1, string word2) {
        // we will start from the last char of both the strings, and check if they are equal, if yes then we don't need to do anything, we will just call the recursion for the next indexes. if they are not equal then we can either delete, insert, or replace charcters, and will accordingly call the recursion, and will take the minimum of all of them and return. the base case would be when either word1 get exhausted, or word2 get exhausted, if the first one get exhausted, then it would mean the minimum number of operations required to convert an empty string that is word1 to word2, which would be basically the current length of word2, j + 1, if the second string get exhausted then we will return the length of the first string, as it would be the min no. char to be deleted to convert word1 to an empty string word2.
        
        // We will have to change these to 1 based indexing to help in represeting them in a dp. 
        
        // Using memoization
        
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        return helper(word1, word2, dp, m, n);
    }
    */
    
    /*
    int minDistance(string word1, string word2) {
        // Using tabulation method
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int j = 0; j <= n; j++) dp[0][j] = j;
                
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int del = 1 + dp[i - 1][j];
                    int repl = 1 + dp[i - 1][j - 1];
                    int insert = 1 + dp[i][j - 1];
                    dp[i][j] = min(del, min(repl, insert));
                }
            }
        }
        return dp[m][n];
    }
    */
    
    
    int minDistance(string word1, string word2) {
        // space optimizing
        int m = word1.length();
        int n = word2.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        
        prev[0] = 0;
        
        for(int j = 0; j <= n; j++) prev[j] = j;
                
        for(int i = 1; i <= m; i++) {
            curr[0] = i;
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    int del = 1 + prev[j];
                    int repl = 1 + prev[j - 1];
                    int insert = 1 + curr[j - 1];
                    curr[j] = min(del, min(repl, insert));
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
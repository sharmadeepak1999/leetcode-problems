class Solution {
public:
    /*
    bool helper(string s, string p, int i, int j) {
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0){
            for(int c = 0; c <= j; c++) {
                if(p[c] != '*') return false;
            }    
            return true;
        }
        
        if(s[i] == p[j] || p[j] == '?') {
            return helper(s, p, i - 1, j - 1);
        } else if(p[j] == '*') {
            return helper(s, p, i - 1, j) || helper(s, p, i, j - 1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        // We will use the basic string matching algo with a little bit of change, if last char of both the strings matches, then we call the recursion for the next indexes, if they don't match, and if the patter char is ?, then also call the recursion for the next indexes, else if the pattern char is a *, we can do a little trick, once we can call recursion assuming the * is an empty char, and we will avoid it, we will decrease the pointer for the pattern, the string to match pointer remains same, and once we match the current string last char with the star, and call recursion on the next index of the to match string without disturbing the pattern, this will ensure that we generate all possible combination with the star. else if we return false. now for the base case, if both the string goes out of bound, then we can say that patter was matching. if the pattern string goes out of bound, and the to match string is still remaining then we will return false, if the to match string remains, and the pattern string goes out of bound then we will check if the pattern string only contains * character as it will match with empty string, else we will return false.
        
        // the brute recursion gives us TLE.
        
        
        int m = s.length(), n = p.length();
        return helper(s, p, m - 1, n - 1);
    }
    */
    
    /*
    bool helper(string s, string p, vector<vector<int>> &dp, int i, int j) {
        if(i == 0 && j == 0) return true;
        if(j == 0 && i >= 1) return false;
        if(i == 0 && j >= 1){
            for(int c = 1; c <= j; c++) {
                if(p[c - 1] != '*') return false;
            }    
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
            return dp[i][j] = helper(s, p, dp, i - 1, j - 1);
        } else if(p[j - 1] == '*') {
            return dp[i][j] = helper(s, p, dp, i - 1, j) || helper(s, p, dp, i, j - 1);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        // We will use memoization, and convert it to 1 based indexing, it gives memory limit exceeded.
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(s, p, dp, m, n);
    }
    
    */
    
    /*
    bool isMatch(string s, string p) {
        // We will do tabulation
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, -1));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++) dp[i][0] = false;
        
        for(int j = 1; j <= n; j++) {
            bool valid = true;
            for(int c = 1; c <= j; c++) {
                if(p[c - 1] != '*') {
                    valid = false;
                    break;
                }
            }
            dp[0][j] = valid;
        }
        
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;                    
                }
            }
        }
        return dp[m][n];
    }
    
    */
    
    
    bool isMatch(string s, string p) {
        // We will space optimize
        int m = s.length(), n = p.length();
        vector<bool> prev(n + 1, false), curr(n + 1, false);
        prev[0] = true;
        
        for(int j = 1; j <= n; j++) {
            bool valid = true;
            for(int c = 1; c <= j; c++) {
                if(p[c - 1] != '*') {
                    valid = false;
                    break;
                }
            }
            prev[j] = valid;
        }
        
        
        for(int i = 1; i <= m; i++) {
            curr[0] = false;    
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if(p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;                    
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
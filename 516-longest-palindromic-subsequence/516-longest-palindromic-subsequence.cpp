class Solution {
public:
    /*
    int helper(string s, int l, int r) {
        if(l == r) return 1;
        if(l > r) return 0;
        if(s[l] == s[r]) return 2 + helper(s, l + 1, r - 1);
        return max(helper(s, l + 1, r), helper(s, l, r - 1));
    }
    int longestPalindromeSubseq(string s) {
        // We will use recursion, we will have pointer on both the end of the string, if they match then we increment the len by 2, for both the characters 1st and the last, and then increment the left pointer, and decrement the right pointer. and call recursion on it. if they are not equal then once increment the left pointer and do recur, and once decrement the right pointer and do recursion, return the max of both the calls.
        return helper(s, 0, s.length() - 1);
    }
    */
    
    
    /*
    int helper(string s, vector<vector<int>> &dp, int l, int r) {
        if(l == r) return 1;
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l] == s[r]) return dp[l][r] = 2 + helper(s, dp, l + 1, r - 1);
        return dp[l][r] = max(helper(s, dp, l + 1, r), helper(s, dp, l, r - 1));
    }
    int longestPalindromeSubseq(string s) {
        // we will use memoization for time optimization
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return helper(s, dp, 0, s.length() - 1);
    }
    */
    

    int longestPalindromeSubseq(string s) {
        // There is another way of solving this, if we reverse the string s, and find the longest common subsequence of s, and reverse s, then it would give me the longest palindromic subsequence.
        
        string rs = s;
        reverse(rs.begin(), rs.end());
        vector<int> prev(s.length() + 1, 0), curr(rs.length() + 1, 0);
        
        prev[0] = curr[0] = 0;
        
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= rs.length(); j++) {
                if(s[i - 1] == rs[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[rs.length()];
    }
};
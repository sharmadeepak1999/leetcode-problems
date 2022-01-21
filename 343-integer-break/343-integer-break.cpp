class Solution {
public:
    int helper(int originalNum, vector<int> &dp, int n) {
        if(dp[n]) return dp[n];
        dp[n] = n == originalNum ? 0 : n;
        for(int i = 1; i < n; i++) {
            int val = helper(originalNum, dp, i) * helper(originalNum, dp, n - i);
            dp[n] = max(dp[n], val);
        }
        return dp[n];
    }
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        return helper(n, dp, n);
    }
};
class Solution {
public:
    // int helper(int originalNum, vector<int> &dp, int n) {
    //     if(dp[n]) return dp[n];
    //     dp[n] = n == originalNum ? 0 : n;
    //     for(int i = 1; i < n; i++) {
    //         int val = helper(originalNum, dp, i) * helper(originalNum, dp, n - i);
    //         dp[n] = max(dp[n], val);
    //     }
    //     return dp[n];
    // }
    // int integerBreak(int n) {
    //     vector<int> dp(n + 1);
    //     dp[1] = 1;
    //     return helper(n, dp, n);
    // }
    
    
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            dp[i] = n == i ? 0 : i;
            for(int j = 1; j < i; j++) {
                int val = dp[j] * dp[i - j];
                dp[i] = max(dp[i], val);
            }
        }
        
        return dp[n];
    }
};
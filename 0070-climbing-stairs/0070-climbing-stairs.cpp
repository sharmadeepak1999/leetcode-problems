class Solution {
public:
    /*
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    */
    int helper(int n, vector<int> &dp) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        
        if(dp[n] != 0) return dp[n];
        
        return dp[n] = (helper(n - 1, dp) + helper(n - 2, dp));
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        return helper(n, dp);
    }
    
};
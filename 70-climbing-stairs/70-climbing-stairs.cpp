class Solution {
public:
    /*
    void helper(int n, int &ways) {
        if(n < 0) return;
        
        if(n == 0) ways++;
        else {
            helper(n - 1, ways);
            helper(n - 2, ways);
        }
    }
    int climbStairs(int n) {
        // We can use recursion, Top to bottom appraoch, we will start from the nth step, here we have two possibility we can come to nth step from n-1 th step or n-2 th step, we call recursion for each of these step, and if we get to n == 0, then we are sure that the path that we took to come down stairs was correct, and we can increment ways counter, and if we get below n which means that we didn't choose the correct step path so we will simply return. 
        
        
        int ways = 0;
        helper(n, ways);
        return ways;
    }
    
    */
    
    
    
    /*
    int helper(int n, vector<int> &dp) {
        if(n == 0 || n == 1) return 1;
        if(dp[n] > 0) return dp[n];
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
    int climbStairs(int n) {
        // We can create memoization using dp vector.
        vector<int> dp(n + 1, false);
        return helper(n, dp);
    }
    */
    
    
    /*
    int climbStairs(int n) {
        // We can use tabulation technique, we will pre set the ways to reach 0 step and 1 step as 1, and then start filling the vector table for further steps, this problem is identical to fibonacci problem. 
        vector<int> dp(n + 1, false);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    */
    
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 1;
        for(int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

};
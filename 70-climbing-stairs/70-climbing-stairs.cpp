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
    
    int helper(int n, vector<int> &dp) {
        if(n == 0 || n == 1) return 1;
        if(dp[n] > 0) return dp[n];
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, false);
        return helper(n, dp);
    }
};
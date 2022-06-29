class Solution {
public:
    /*
    int helper(vector<int>& coins, int i, int amount) {
        if(i == 0) {
            return amount % coins[0] == 0;
        }
        if(amount == 0) return 1;
        
        int nottake = helper(coins, i - 1, amount);
        int take = 0;
        if(coins[i] <= amount) {
            take = helper(coins, i, amount - coins[i]);
        }
        return take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        // use recursion, return 1 if possible, else 0. return addition of take and nottake 
        return helper(coins, coins.size() - 1, amount);
    }
    */
    
    /*
    int helper(vector<int>& coins, vector<vector<int>> &dp, int i, int amount) {
        if(i == 0) {
            return amount % coins[0] == 0;
        }
        if(amount == 0) return 1;
        
        if(dp[i][amount] != -1) return dp[i][amount];
        int nottake = helper(coins, dp, i - 1, amount);
        int take = 0;
        if(coins[i] <= amount) {
            take = helper(coins, dp, i, amount - coins[i]);
        }
        return dp[i][amount] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        // use memoization to optimize the time.
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return helper(coins, dp, coins.size() - 1, amount);
    }
    */
    
    /*
    int change(int amount, vector<int>& coins) {
        // use tabulation.
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        
        for(int amt = 0; amt <= amount; amt++) {
            if(amt % coins[0] == 0) {
                dp[0][amt] = 1;
            }    
        }
        
        for(int i = 0; i < coins.size(); i++) {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < coins.size(); i++) {
            for(int amt = 0; amt <= amount; amt++) {
                int nottake = dp[i - 1][amt];
                int take = 0;
                if(coins[i] <= amt) {
                    take = dp[i][amt - coins[i]];
                }
                dp[i][amt] = take + nottake;
            }
        }
        return dp[coins.size() - 1][amount];
    }
    */
    
    int change(int amount, vector<int>& coins) {
        // use space optimization.
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        
        prev[0] = curr[0] = 1;
        
        for(int amt = 0; amt <= amount; amt++) {
            if(amt % coins[0] == 0) {
                prev[amt] = 1;
            }    
        }
        
        for(int i = 1; i < coins.size(); i++) {
            for(int amt = 0; amt <= amount; amt++) {
                int nottake = prev[amt];
                int take = 0;
                if(coins[i] <= amt) {
                    take = curr[amt - coins[i]];
                }
                curr[amt] = take + nottake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};
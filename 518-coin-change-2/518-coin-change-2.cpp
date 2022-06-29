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
};
class Solution {
public:
    int helper(vector<int>& coins, vector<vector<int>> &dp, int amount, int i) {
        if(amount == 0) return 0;
        if(i == 0) {
            if(amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int nottake = helper(coins, dp, amount, i - 1);
        int take = 1e9;
        
        if(coins[i] <= amount) take = 1 + helper(coins, dp, amount - coins[i], i);
        return dp[i][amount] = min(nottake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = helper(coins, dp, amount, n - 1);
        return res == 1e9 ? -1 : res;
    }
};
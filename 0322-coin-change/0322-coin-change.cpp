class Solution {
    int helper(vector<int> &coins, int amount, int i, vector<vector<int>> &dp) {
        if(amount == 0) return 0;
        if(i == 0) {
            if(amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }
        if(dp[amount][i] != -1) return dp[amount][i];
        int pick = 1e9, notpick = 1e9;
        if(amount >= coins[i]) pick = 1 + helper(coins, amount - coins[i], i, dp);
        notpick = helper(coins, amount, i - 1, dp);
        return dp[amount][i] = min(pick, notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(10001, vector<int>(coins.size(), -1));
        int ans = helper(coins, amount, coins.size() - 1, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
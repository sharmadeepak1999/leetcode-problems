class Solution {
public:
    int helper(vector<int> &coins, vector<vector<int>> &dp, int amount, int i) {
        if(amount == 0) return 1;
        if(i == 0) {
            if(amount % coins[0] == 0) return 1;
            return 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int nottake = helper(coins, dp, amount, i - 1);
        int take = 0;
        if(coins[i] <= amount) take = helper(coins, dp, amount - coins[i], i);
        return dp[i][amount] = nottake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(coins, dp, amount, n - 1);
    }
};
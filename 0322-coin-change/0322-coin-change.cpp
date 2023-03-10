class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        for(int i = 0; i < n; i++) dp[i][0] = 0;
        for(int ai = 0; ai <= amount; ai++) {
            if(ai % coins[0] == 0) dp[0][ai] = ai / coins[0];
        }
        for(int i = 1; i < n; i++) {
            for(int ai = 0; ai <= amount; ai++) {
                int nottake = dp[i-1][ai];
                int take = 1e9;
                if(coins[i] <= ai) take = 1 + dp[i][ai - coins[i]];
                dp[i][ai] = min(nottake, take);
            }
        }
        int res = dp[n -1][amount];
        return res == 1e9 ? -1 : res;
    }
};
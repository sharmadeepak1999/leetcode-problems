class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for(int ai = 0; ai <= amount; ai++) {
            if(ai % coins[0] == 0) dp[0][ai] = 1;
        }
        for(int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int ai = 0; ai <= amount; ai++) {
                int nottake = dp[i - 1][ai];
                int take = 0;
                if(coins[i] <= ai) take = dp[i][ai - coins[i]];
                dp[i][ai] = nottake + take;
            }
        }
        return dp[n - 1][amount];
    }
};
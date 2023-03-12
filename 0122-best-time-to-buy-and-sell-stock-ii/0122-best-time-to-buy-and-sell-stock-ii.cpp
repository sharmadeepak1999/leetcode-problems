class Solution {
public:
    int helper(vector<int> &prices, vector<vector<int>> &dp, int n, int i, int buy) {
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 1) {
            return dp[i][buy] = max(-prices[i] + helper(prices, dp, n, i + 1, 0), helper(prices, dp, n, i + 1, 1));
        } else return dp[i][buy] = max(prices[i] + helper(prices, dp, n, i + 1, 1), helper(prices, dp, n, i + 1, 0));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return helper(prices, dp, n, 0, 1);
    }
};
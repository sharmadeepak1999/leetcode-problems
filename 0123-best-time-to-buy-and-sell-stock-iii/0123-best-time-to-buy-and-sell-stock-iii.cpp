class Solution {
public:
    int helper(vector<int> &prices, vector<vector<vector<int>>> &dp, int n, int i, int buy, int nots) {
        if(i == n) return 0;
        if(nots == 2) return 0;
        if(dp[i][buy][nots] != -1) return dp[i][buy][nots];
        if(buy) {
            return dp[i][buy][nots] = max(-prices[i] + helper(prices, dp, n, i + 1, 0, nots), helper(prices, dp, n, i + 1, 1, nots));
        } else {
            return dp[i][buy][nots] = max(prices[i] + helper(prices, dp, n, i + 1, 1, nots + 1), helper(prices, dp, n, i + 1, 0, nots));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, -1)));
        return helper(prices, dp, n, 0, 1, 0);
    }
};
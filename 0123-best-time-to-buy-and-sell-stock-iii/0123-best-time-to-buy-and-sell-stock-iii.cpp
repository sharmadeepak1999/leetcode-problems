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
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int nots = 0; nots < 2; nots++) {
                    if(buy) {
                        dp[i][buy][nots] = max(-prices[i] + dp[i + 1][0][nots], dp[i + 1][1][nots]);
                    } else dp[i][buy][nots] = max(prices[i] + dp[i + 1][1][nots + 1], dp[i + 1][0][nots]);
                }
            }
        }
        return dp[0][1][0];
    }
};
class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        // using tabulation
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        // skipping base cases as the dp array is already initialized with 0
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
        
                if(buy) {
                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    profit = max(prices[i] + dp[i + 1][1] - fee, dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];    
    }
};
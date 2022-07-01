class Solution {
public:
    /*
    int helper(vector<int>& prices, int i, int buy) {
        if(i >= prices.size()) return 0;
        int profit = 0;
        
        if(buy) {
            profit = max(-prices[i] + helper(prices, i + 1, 0), helper(prices, i + 1, 1));
        } else {
            profit = max(prices[i] + helper(prices, i + 2, 1), helper(prices, i + 1, 0));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return helper(prices, 0, 1);
    }
    */
    
    
    int helper(vector<int>& prices, vector<vector<int>> &dp, int i, int buy) {
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        
        if(buy) {
            profit = max(-prices[i] + helper(prices, dp, i + 1, 0), helper(prices, dp, i + 1, 1));
        } else {
            profit = max(prices[i] + helper(prices, dp, i + 2, 1), helper(prices, dp, i + 1, 0));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, dp, 0, 1);
    }
};
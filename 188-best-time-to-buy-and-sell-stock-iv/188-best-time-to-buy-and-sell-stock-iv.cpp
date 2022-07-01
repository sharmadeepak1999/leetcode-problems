class Solution {
public:
    /*
    int helper(vector<int>& prices, int i, int buy, int cap) {
        if(cap == 0 || i == prices.size()) return 0;
        
        int profit = 0;
        
        if(buy) {
            profit = max(-prices[i] + helper(prices, i + 1, 0, cap), helper(prices, i + 1, 1, cap));
        } else {
            profit = max(prices[i] + helper(prices, i + 1, 1, cap - 1), helper(prices, i + 1, 0, cap));
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return helper(prices, 0, 1, k);
    }
    */
    
    int helper(vector<int>& prices, vector<vector<vector<int>>> &dp, int i, int buy, int cap) {
        if(cap == 0 || i == prices.size()) return 0;
        
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        
        int profit = 0;
        
        if(buy) {
            profit = max(-prices[i] + helper(prices, dp, i + 1, 0, cap), helper(prices, dp, i + 1, 1, cap));
        } else {
            profit = max(prices[i] + helper(prices, dp, i + 1, 1, cap - 1), helper(prices, dp, i + 1, 0, cap));
        }
        return dp[i][buy][cap] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        // using memoizaiton
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(prices, dp, 0, 1, k);
    }
};
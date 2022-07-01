class Solution {
public:
    /*
    int helper(vector<int>& prices, int i, int buy, int cap) {
        if(cap == 0) return 0;
        if(i == prices.size()) return 0;
        
        int profit = 0;
        if(buy) {
            profit = max(-prices[i] + helper(prices, i + 1, 0, cap), helper(prices, i + 1, 1, cap));    
        } else {
            profit = max(prices[i] + helper(prices, i + 1, 1, cap - 1), helper(prices, i + 1, 0, cap));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return helper(prices, 0, 1, 2);        
    }
    */
    
    /*
    int helper(vector<int>& prices, vector<vector<vector<int>>> &dp, int i, int buy, int cap) {
        if(cap == 0) return 0;
        if(i == prices.size()) return 0;
        
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        int profit = 0;
        if(buy) {
            profit = max(-prices[i] + helper(prices, dp, i + 1, 0, cap), helper(prices, dp, i + 1, 1, cap));    
        } else {
            profit = max(prices[i] + helper(prices, dp, i + 1, 1, cap - 1), helper(prices, dp, i + 1, 0, cap));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // using memoization
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, dp, 0, 1, 2);        
    }
    */
    
    
    int maxProfit(vector<int>& prices) {
        // using tabulation
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        // there is no need to write the base case here as we already have initialized the dp array with 0.
        
        for(int i = 0; i <= n; i++) {
            for(int buy = 0; buy <= 1; buy++) {
                dp[i][buy][0] = 0;
            }
        }
        
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 0; cap <= 2; cap++) {
                dp[n][buy][cap] = 0;
            }
        }
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                // starting from 1 because for cap = 0, we return from the recur, so not considered
                for(int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);    
                    } else {
                        profit = max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
                    }
                    dp[i][buy][cap] = profit;
                }
            }
        }
        
        return dp[0][1][2];        
    }
};
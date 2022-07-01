class Solution {
public:
    /*
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        int b = prices[0];
        for(auto &p : prices) {
            if(p > b) {
                profit += p - b;
            }
            b = p;
        }
        return profit;
      }
      */
    
    /*
    int helper(vector<int>& prices, int i, int buy) {
        if(i == prices.size()) return 0;
        int profit = 0;
        if(buy) {
            // Buy at the current price, money will go out of the pocket, so it will reduced form the profit, or we can choose to not buy, then we will just call recursion for next index, take max of these.
            profit = max(-prices[i] + helper(prices, i + 1, 0), helper(prices, i + 1, 1));
        } else {
            // Sell or not sell depends, add current prices to profit if decides to sell.
            profit = max(prices[i] + helper(prices, i + 1, 1), helper(prices, i + 1, 0));
        }
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        return helper(prices, 0, 1);
    }
    */
    
    /*
    int helper(vector<int>& prices, vector<vector<int>> &dp, int i, int buy) {
        if(i == prices.size()) return 0;
    
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int profit = 0;
    
        if(buy) {
            // Buy at the current price, money will go out of the pocket, so it will reduced form the profit, or we can choose to not buy, then we will just call recursion for next index, take max of these.
            profit = max(-prices[i] + helper(prices, dp, i + 1, 0), helper(prices, dp, i + 1, 1));
        } else {
            // Sell or not sell depends, add current prices to profit if decides to sell.
            profit = max(prices[i] + helper(prices, dp, i + 1, 1), helper(prices, dp, i + 1, 0));
        }
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        // Using memoization
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices, dp, 0, 1);
    }
    */
    

    
    int maxProfit(vector<int>& prices) {
        // Using tabulation
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy) {
                    // Buy at the current price, money will go out of the pocket, so it will reduced form the profit, or we can choose to not   buy, then we will just call recursion for next index, take max of these.
                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    // Sell or not sell depends, add current prices to profit if decides to sell.
                    profit = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
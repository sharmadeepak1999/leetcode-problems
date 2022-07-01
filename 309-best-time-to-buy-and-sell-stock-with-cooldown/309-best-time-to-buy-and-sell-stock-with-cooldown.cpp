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
    
    /*
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
        // using memoization
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, dp, 0, 1);
    }
    */
    
    int maxProfit(vector<int>& prices) {
        // using tabulation, we can do another space optimization by using 3 vector array front1, front2, curr;
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        
        // skipping base cases as the dp array is already initialized with 0
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
        
                if(buy) {
                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    profit = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
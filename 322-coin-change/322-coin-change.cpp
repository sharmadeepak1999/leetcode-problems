class Solution {
public:
    /*
    int helper(vector<int>& coins, int i, int amount) {
        if(i == 0) {
            return amount % coins[0] == 0 ? amount / coins[0] : 1e9;
        }
        
        int nottake = helper(coins, i - 1, amount);
        int take = 1e9;
        if(coins[i] <= amount) {
            take = 1 + helper(coins, i, amount - coins[i]);
        }
        return min(take, nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // We will use recursion, we visit every coin, we can either take it or not take it, if we do not take it, then we can simply call the recursion for the next coin, if we take it, we have to first check if the current coin is less than or equal to the amount, if yes then we call the recursion for the same coin but with decrease amount, and also add 1 to the take result so as to denote one coin is taken, after that we return the min of take and nottake. the base case would be when i becomes 0, in that case we will check if the amount can be achieved by using the current coin once or multiple times, we return the no. of coins required to get the amount, simple division, or else we return a negative value denoting amoount cannot be formed. this gives tle.
        int ans = helper(coins, coins.size() - 1, amount);
        return ans == 1e9 ? -1 : ans;
    }
    */
    
    
    
    /*
    int helper(vector<int>& coins, vector<vector<int>>& dp, int i, int amount) {
        if(i == 0) {
            return amount % coins[0] == 0 ? amount / coins[0] : 1e9;
        }
     
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int nottake = helper(coins, dp, i - 1, amount);
        int take = 1e9;
        if(coins[i] <= amount) {
            take = 1 + helper(coins, dp, i, amount - coins[i]);
        }
        return dp[i][amount] = min(take, nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // We will use memoization
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = helper(coins, dp, coins.size() - 1, amount);
        return ans == 1e9 ? -1 : ans;
    }
    */
    
    
    
    int helper(vector<int>& coins, vector<vector<int>>& dp, int i, int amount) {
        if(i == 0) {
            return amount % coins[0] == 0 ? amount / coins[0] : 1e9;
        }
     
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int nottake = helper(coins, dp, i - 1, amount);
        int take = 1e9;
        if(coins[i] <= amount) {
            take = 1 + helper(coins, dp, i, amount - coins[i]);
        }
        return dp[i][amount] = min(take, nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // We will use tabulation
        vector<int> prev(vector<int>(amount + 1, -1)), curr(vector<int>(amount + 1, -1));
        
        for(int amt = 0; amt <= amount; amt++) {
            prev[amt] = amt % coins[0] == 0 ? amt / coins[0] : 1e9;
        }
        
        for(int i = 1; i < coins.size(); i++) {
            for(int amt = 0; amt <= amount; amt++) {
                int nottake = prev[amt];
                int take = 1e9;
                if(coins[i] <= amt) {
                    take = 1 + curr[amt - coins[i]];
                }
                curr[amt] = min(take, nottake);
            }
            prev = curr;
        }
        
        int ans = prev[amount];
        return ans == 1e9 ? -1 : ans;
    }
};
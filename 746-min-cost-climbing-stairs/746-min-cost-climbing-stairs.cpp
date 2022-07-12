class Solution {
public:
    int helper(vector<int>& cost, vector<int> &dp, int i) {
        if(i >= cost.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = cost[i] + min(helper(cost, dp, i + 1), helper(cost, dp, i + 2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        
        return min(helper(cost, dp, 0), helper(cost, dp, 1));
    }
};
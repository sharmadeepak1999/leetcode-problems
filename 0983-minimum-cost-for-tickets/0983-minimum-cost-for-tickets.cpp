class Solution {
public:
    int helper(vector<int> &days, vector<int> &costs, vector<vector<int>> &dp, int index, int curr) {
        if(index >= days.size()) return 0;
        if(dp[index][curr] != -1) return dp[index][curr];
        if(days[index] <= curr) {
            return dp[index][curr] = helper(days, costs, dp, index + 1, curr);
        } else {
            int a = costs[0] + helper(days, costs, dp, index + 1, days[index]);
            int b = costs[1] + helper(days, costs, dp, index + 1, days[index] + 6);
            int c = costs[2] + helper(days, costs, dp, index + 1, days[index] + 29);
            
            return dp[index][curr] = min(a, min(b, c));
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n + 1, vector<int>(395, -1));
        return helper(days, costs, dp, 0, 0);
    }
};
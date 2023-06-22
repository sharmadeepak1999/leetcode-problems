class Solution {
    int helper(vector<int> &nums, vector<vector<int>> &dp, int i, int prev) {
        if(i >= nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int pick = INT_MIN, notpick = INT_MIN;
        if(prev - 1 == -1 || i - prev + 1 > 1) {
            pick = nums[i] + helper(nums, dp, i + 2, i);
        }
        notpick = helper(nums, dp, i + 1, prev);
        return dp[i][prev] = max(pick, notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(nums, dp, 0, 0);
    }
};
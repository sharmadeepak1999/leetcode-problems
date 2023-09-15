class Solution {
    int helper(vector<int> &nums, int prev, int i, vector<vector<int>> &dp) {
        if(i == nums.size()) return 0;
        if(dp[prev + 1][i] != -1) return dp[prev + 1][i];
        int notpick = helper(nums, prev, i + 1, dp);
        int pick = 0;
        if(prev == -1 || nums[prev] < nums[i]) {
            pick = 1 + helper(nums, i, i + 1, dp);
        }
        return dp[prev + 1][i] = max(pick, notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(nums, -1, 0, dp);
    }
};
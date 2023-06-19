class Solution {
    int helper(vector<int> &nums, vector<vector<int>> &dp, int i, int prev) {
        if(i == nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int pick = 0, notpick = 0;
        
        if(prev == 0 || nums[i] > nums[prev - 1]) {
            pick = 1 + helper(nums, dp, i + 1, i + 1);
        }
        notpick = helper(nums, dp, i + 1, prev);
        return dp[i][prev] = max(pick, notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(nums, dp, 0, 0);
    }
};
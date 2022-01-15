class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int index) {
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        return dp[index] = max(nums[index] + helper(nums, dp, index + 2), helper(nums, dp, index + 1));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, dp, 0);
    }
};
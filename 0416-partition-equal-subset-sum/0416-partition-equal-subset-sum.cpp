class Solution {
public:
    bool helper(vector<int> &nums, vector<vector<int>> &dp, int target, int i) {
        if(target == 0) return true;
        if(i == 0) return false;
        if(dp[i][target] != -1) return dp[i][target];
        int nottake = helper(nums, dp, target, i - 1);
        int take = false;
        if(target >= nums[i]) take = helper(nums, dp, target - nums[i], i - 1);
        return dp[i][target] = take or nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int osum = accumulate(nums.begin(), nums.end(), 0);
        if(osum % 2 == 1) return false;
        vector<vector<int>> dp(n, vector<int>(osum / 2 + 1, -1));
        return helper(nums, dp, osum / 2, n - 1);
    }
};
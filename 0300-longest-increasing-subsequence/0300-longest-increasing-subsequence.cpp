class Solution {
public:
    int helper(vector<int> &nums, vector<vector<int>> &dp, int n, int i, int prevIndex) {
        if(i == n) return 0;
        if(dp[i][prevIndex] != -1) return dp[i][prevIndex];
        if(prevIndex == 0 || nums[prevIndex - 1] < nums[i]) return dp[i][prevIndex] = max(1 + helper(nums, dp, n, i + 1, i + 1), helper(nums, dp, n, i + 1, prevIndex));
        return dp[i][prevIndex] = helper(nums, dp, n, i + 1, prevIndex);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(nums, dp, n, 0, 0);
    }
};
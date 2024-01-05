class Solution {
public:
    int helper(vector<int> &nums, int i, int prev, vector<vector<int>> &dp) {
        if(i == nums.size()) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        
        if(prev == -1 || nums[prev] < nums[i]) {
            return dp[i][prev + 1] = max(1 + helper(nums, i + 1, i, dp), helper(nums, i + 1, prev, dp));
        }
        
        return dp[i][prev + 1] = helper(nums, i + 1, prev, dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(nums, 0, -1, dp);
    }
};
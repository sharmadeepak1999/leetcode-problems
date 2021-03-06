class Solution {
public:
    /*
    int helper(vector<int>& nums, int i, int target){
        if(i == 0) {
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        
        int nottake = helper(nums, i - 1, target);
        int take = 0;
        if(nums[i] <= target) {
            take = helper(nums, i - 1, target - nums[i]);
        }
        return take + nottake;
    } 
    
    int findTargetSumWays(vector<int>& nums, int target) {
        // This problem can be reduced to the problem to divide the array into two subset whose different is target. s1 - s2 = target, (total - s2) - s2 = target, s2 = (total - target) / 2, so we just need to find the subset whose sum is s2. we have to take care of 0s if there are zeros in the array, then we will write additional base cases, like if we have 0 in the base case, and target is 0, then it will be counted as 2 ways, if not then 1.
        
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total - target < 0 || (total - target) % 2) return 0;
        return helper(nums, nums.size() - 1, (total - target) / 2);
    }
    */
    
    /*
    int helper(vector<int>& nums, vector<vector<int>>& dp, int i, int target){
        if(i == 0) {
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int nottake = helper(nums, dp, i - 1, target);
        int take = 0;
        if(nums[i] <= target) {
            take = helper(nums, dp, i - 1, target - nums[i]);
        }
        return dp[i][target] = take + nottake;
    } 
    
    int findTargetSumWays(vector<int>& nums, int target) {
        // we will use dp to optimize the time.
        
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total - target < 0 || (total - target) % 2) return 0;
        vector<vector<int>> dp(nums.size(), vector<int>((total - target) / 2 + 1, -1));
        return helper(nums, dp, nums.size() - 1, (total - target) / 2);
    }
    */
    
    /*
    int findTargetSumWays(vector<int>& nums, int target) {
        // we will use tabulation.
        
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total - target < 0 || (total - target) % 2) return 0;
        int newTarget = (total - target) / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(newTarget + 1, 0));
        
        dp[0][0] = 1;
        if(nums[0] == 0) dp[0][0] = 2;
        if(nums[0] != 0 && nums[0] <= newTarget) dp[0][nums[0]] = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            for(int t = 0; t <= newTarget; t++) {
                int nottake = dp[i - 1][t];
                int take = 0;
                if(nums[i] <= t) {
                    take = dp[i - 1][t - nums[i]];
                }
                dp[i][t] = take + nottake;
            }
        }
        return dp[nums.size() - 1][(total - target) / 2];
    }
    */
    
    int findTargetSumWays(vector<int>& nums, int target) {
        // we will space optimize.
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total - target < 0 || (total - target) % 2) return 0;
        int newTarget = (total - target) / 2;
        vector<int> prev(vector<int>(newTarget + 1, 0)), curr(vector<int>(newTarget + 1, 0));
        
        prev[0] = 1;
        if(nums[0] == 0) prev[0] = 2;
        if(nums[0] != 0 && nums[0] <= newTarget) prev[nums[0]] = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            for(int t = 0; t <= newTarget; t++) {
                int nottake = prev[t];
                int take = 0;
                if(nums[i] <= t) {
                    take = prev[t - nums[i]];
                }
                curr[t] = take + nottake;
            }
            prev = curr;
        }
        return prev[(total - target) / 2];
    }
};
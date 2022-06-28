class Solution {
public:
    /*
    bool helper(vector<int>& nums, int i, int target) {
        if(i == 0) return nums[0] == target;
        if(target == 0) return true;
        
        bool nottake = helper(nums, i - 1, target);
        bool take = false;
        if(nums[i] <= target) {
            take = helper(nums, i - 1, target - nums[i]);        
        }
        return take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        // Since we have to partition the array into two equal sum parts, that means that sum of both part should be equal to the sum of the whole array, which in turn means that each partition should have sum equal to the half of the sum of whole array, so it reduces to the target sum problem, we will use recursion if we get to base, that is index 0, we check if it is equal to the target, if yes return true, false otherwise, else we do recursion once while taking the current element and once by not taking the current element, when taking the current element we will make sure that the current element is smaller than the target, we return the boolean value of both the calls, we will also keep a check if target becomes 0 we will return true; 
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        return helper(nums, nums.size() - 1, sum / 2);
    }
    */
    
    
    bool helper(vector<int>& nums, vector<vector<int>> &dp, int i, int target) {
        if(target == 0) return true;
        if(i == 0) return nums[0] == target;
        
        if(dp[i][target] != -1) return dp[i][target];
        bool nottake = helper(nums, dp, i - 1, target);
        bool take = false;
        if(nums[i] <= target) {
            take = helper(nums, dp, i - 1, target - nums[i]);        
        }
        return dp[i][target] = (take || nottake);
    }
    bool canPartition(vector<int>& nums) {
        // We will optimize using dp
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        vector<vector<int>> dp(nums.size(), vector<int>((sum / 2) + 1, -1));
        return helper(nums, dp, nums.size() - 1, sum / 2);
    }
};
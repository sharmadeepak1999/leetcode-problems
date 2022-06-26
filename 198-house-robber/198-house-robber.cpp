class Solution {
public:
    /*
    int helper(vector<int>& nums, int i, int n) {
        if(i > n) return 0;
        
        int maxMoney = 0;
        for(int j = i; j < n; j++) {
            maxMoney = max(maxMoney, nums[j] + helper(nums, j + 2, n));
        }
        return maxMoney; 
    }
    int rob(vector<int>& nums) {
        // We stand at every house, and add the current house money with the result of recursion on the house 2nd to the current one, we will compare it with so far max money, and at last return it.
        return helper(nums, 0, nums.size());
    }
    */
    
    /*
    int helper(vector<int>& nums, int n) {
        if(n < 0) return 0;
        if(n == 0) return nums[n];
        
        int pick = nums[n] + helper(nums, n - 2);
        int notpick = helper(nums, n - 1);
        return max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        // We can use the pick and not pick method, we can start from the end and first pick the last element and call the recursion on the n - 2 th element, and also once don't pick last element and call the recursion on the n - 1 th element. and return the max of the pick and notpick, the base case would if n < 0 then return 0, and if n == 0 return the 0th element. 
        
        return helper(nums, nums.size() - 1);
    }
    */
    
    
    int helper(vector<int>& nums, vector<int>& dp, int n) {
        if(n < 0) return 0;
        if(n == 0) return nums[n];

        if(dp[n] != -1) return dp[n];
        
        int pick = nums[n] + helper(nums, dp, n - 2);
        int donotpick = helper(nums, dp, n - 1);
        
        return dp[n]=max(pick, donotpick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, dp, nums.size() - 1);
    }
};
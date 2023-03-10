class Solution {
public:
    int helper(vector<int> &nums, int target, int i) {
        if(i == 0) {
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        int nottake = helper(nums, target, i - 1);
        int take = 0;
        if(nums[i] <= target) take = helper(nums, target - nums[i], i - 1);
        
        return nottake + take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if((total - target) < 0 || (total - target) % 2 == 1) return 0;
        int sum = (total - target) / 2;
        return helper(nums, sum, n - 1);
    }
};
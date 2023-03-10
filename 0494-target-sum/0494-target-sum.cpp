class Solution {
public:
    int helper(vector<int> &nums, int target, int sum, int i) {
        if(i == 0) {
            int cnt = 0;
            if(sum + nums[0] == target) cnt++;
            if(sum - nums[0] == target) cnt++;
            return cnt;
        }
        int plus = helper(nums, target, sum + nums[i], i - 1);
        int minus = helper(nums, target, sum - nums[i], i - 1);
        
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(nums, target, 0, n - 1);
    }
};
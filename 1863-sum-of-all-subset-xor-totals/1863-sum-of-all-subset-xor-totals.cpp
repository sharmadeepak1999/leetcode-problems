class Solution {
public:
    int helper(vector<int>& nums, int i, int XOR) {
        if(i >= nums.size()) return XOR;
        return helper(nums, i + 1, XOR ^ nums[i]) + helper(nums, i + 1, XOR);
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};
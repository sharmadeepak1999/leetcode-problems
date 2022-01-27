class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int size = nums.size(), res = nums[1] - nums[0], minVal = nums[0];
        for(int i = 1; i < size; i++) {
            res = max(res, nums[i] - minVal);
            minVal = min(minVal, nums[i]);
        }
        return res <= 0 ? -1 : res;
    }
};
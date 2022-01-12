class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> cummulativeSum;
        cummulativeSum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            cummulativeSum.push_back(nums[i] + cummulativeSum[i - 1]);
        }
        return cummulativeSum;
    }
};
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = INT_MIN, size = nums.size();
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                if((nums[j] - nums[i]) > maxDiff) {
                    maxDiff = nums[j] - nums[i];
                }
            }
        }
        return maxDiff <= 0 ? -1 : maxDiff;
    }
};
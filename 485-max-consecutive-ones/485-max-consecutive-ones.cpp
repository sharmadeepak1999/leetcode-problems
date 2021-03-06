class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConOne = 0, currMax = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                currMax++;
                maxConOne = max(maxConOne, currMax);
            } else {
                currMax = 0;
            }
        }
        return maxConOne;
    }
};
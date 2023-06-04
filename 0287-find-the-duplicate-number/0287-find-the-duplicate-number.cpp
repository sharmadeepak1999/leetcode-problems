class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        
        while(nums[i] >= 1) {
            nums[i] = nums[i] * -1;
            i = abs(nums[i]);
        }
        return i;
    }
};
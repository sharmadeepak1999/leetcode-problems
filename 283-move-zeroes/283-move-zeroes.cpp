class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(nums[i] != 0) {
                nums[idx] = nums[i];
                idx++;
            }
        }
        for(int i = idx; i < size; i++) {
            nums[i] = 0;
        }
    }
};
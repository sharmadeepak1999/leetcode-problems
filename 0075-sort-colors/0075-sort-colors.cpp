class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        
        for(int i = 0; i < nums.size() && i <= h; i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[l++]);
            }
            if(nums[i] == 2) {
                swap(nums[i--], nums[h--]);
            }
        }
    }
};
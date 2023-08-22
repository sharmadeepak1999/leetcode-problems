class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        
        while(j < nums.size()) {
            while(j < nums.size() && nums[j] == 0) j++;
            if(j < nums.size()) {
                swap(nums[i], nums[j]);
                j++;
                i++;
            }
        }
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j;
        i = j = 0;
        int z = 0;
        while(i < nums.size()) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            } else z++;
            i++;
        }
        while(z) {
            nums[nums.size() - z] = 0;
            z--;
        }
    }
};
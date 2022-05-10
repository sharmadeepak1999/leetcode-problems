class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    /*
        // traverse from begin, and if non zero then update the value of the pointer maintained with current value and increment the pointer, and if zero then count increment. after first loop insert zero in the remaining part of the array.
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
    */
        
        // traverse from begin, and if non zero then swap from the other pointer maintained and increment that pointer. zero will be taken care by itself using this algo.
        int i, j;
        i = j = 0;
        int z = 0;
        while(i < nums.size()) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
    }
};
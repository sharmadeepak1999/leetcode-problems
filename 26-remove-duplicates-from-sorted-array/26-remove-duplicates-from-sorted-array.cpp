class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) {
            return 0;
        }
        int res = 1;
        for(int i = 1; i < size; i++) {
            if(nums[i] != nums[res - 1]) {
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }
};
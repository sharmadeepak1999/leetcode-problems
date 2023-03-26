class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        for(; j < n; j++) {
            while(j < n - 1 && nums[j] == nums[j + 1]) j++;
            nums[i++] = nums[j];
        }
        return i;
    }
};
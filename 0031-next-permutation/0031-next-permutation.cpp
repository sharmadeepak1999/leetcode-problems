class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        int j = -1;
        while(i > 0) {
            if(nums[i - 1] < nums[i]) {
                j = i - 1;
                break;
            }
            i--;
        }
        if(j == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        i = nums.size() - 1;
        while(i >= 0) {
            if(nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
                break;
            }
            i--;
        }
        
        reverse(nums.begin() + j + 1, nums.end());
    }
    // 1 2 2 3 4 5 1
    //         5 4 1
};
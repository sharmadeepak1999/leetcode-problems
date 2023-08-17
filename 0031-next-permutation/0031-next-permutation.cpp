class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i = n - 1;
        int j = -1;
        while(i >= 1) {
            if(nums[i] > nums[i - 1]) {
                j = i - 1;
                break;
            }
            i--;
        }
        if(j == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        i = n - 1;
        while(i > j) {
            if(nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
                break;
            }
            i--;
        }
        
        reverse(nums.begin() + j + 1, nums.end());
    }
};
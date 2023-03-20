class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        
        for(int k = 0; j >= k && k < nums.size(); k++) {
            if(nums[k] == 0) {
                swap(nums[i], nums[k]);
                i++;
            } else if(nums[k] == 2) {
                swap(nums[k--], nums[j]);
                j--;
            }
        }
    }
};
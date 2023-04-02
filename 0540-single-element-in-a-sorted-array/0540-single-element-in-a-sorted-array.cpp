class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 2;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(mid & 1) {
                if(nums[mid] == nums[mid + 1]) high = mid - 1;
                else low = mid + 1;
            } else {
                if(nums[mid] != nums[mid + 1]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return nums[low];
    }
};
       
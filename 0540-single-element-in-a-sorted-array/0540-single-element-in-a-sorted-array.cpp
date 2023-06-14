class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int n = nums.size();
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(mid % 2 == 0) {
                if(mid + 1 < n)
                {
                    if(nums[mid + 1] != nums[mid]) high = mid - 1;
                    else low = mid + 1;
                } else return nums[mid];
            } else {
                if(mid > 0){
                    if(nums[mid - 1] != nums[mid]) high = mid - 1;
                    else low = mid + 1;
                } else return nums[mid];
            }
        }
        return nums[low];
    }
};
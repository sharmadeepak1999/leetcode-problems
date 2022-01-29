class Solution {
public:
    int findPeakElement(vector<int>& nums) {
//         int size = nums.size();
//         if(size == 1) return 0;
//         if(nums[0] > nums[1]) return 0;
//         if(nums[size - 1] > nums[size - 2]) return size - 1;
        
//         for(int i = 1; i < size - 1; i++)
//             if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
//         return -1;
        
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if((mid == 0 || nums[mid - 1] <= nums[mid]) && (mid == nums.size() - 1 || nums[mid] >= nums[mid + 1])){
                return mid;
            }
            if(mid > 0 && nums[mid - 1] >= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lb = 0, ub = nums.size() - 1;
        
        int ans = 0;
        while(lb <= ub) {
            int mid = (lb + ub) / 2;
            
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) ub = mid - 1;
            else {
                lb = mid + 1;
                ans = mid + 1;
            }
        }
        return ans;
    }
};
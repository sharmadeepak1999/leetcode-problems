class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        int s = 0, e = nums.size() - 1, mid;
        while(s <= e) {
            mid = (s + e) / 2;
        
            if(nums[mid] == target) {
                ans[0] = mid;
                e = mid - 1;
            } else if(nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        
        s = 0, e = nums.size() - 1;
        while(s <= e) {
            mid = (s + e) / 2;
        
            if(nums[mid] == target) {
                ans[1] = mid;
                s = mid + 1;
            } else if(nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};
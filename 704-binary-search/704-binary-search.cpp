class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, mid;
        
        while(lo <= hi) {
            mid = (lo + hi) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};
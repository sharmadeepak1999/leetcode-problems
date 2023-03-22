class Solution {
public:
    int merge(vector<int> &nums, int s, int e) {
        int count = 0;
        int mid = (s + e) / 2;
        int i = s, j = mid + 1;
        for(; i <= mid; i++) {
            while(j <= e && nums[i] > ((long) nums[j] * 2)) {
                j++;
            }
            count += (j - (mid + 1));
        }
        vector<int> temp(e - s + 1, 0);
        
        i = s, j = mid + 1;
        int k = 0;
        while(i <= mid && j <= e) {
            if(nums[i] <= nums[j]) {
               temp[k++] = nums[i++]; 
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= e) temp[k++] = nums[j++];
        
        for(int i = s; i <= e; i++) {
            nums[i] = temp[i - s];
        }
        return count;
    }
    int helper(vector<int> &nums, int s, int e) {
        if(s >= e) return 0;
        
        int mid = (s + e) / 2;
        int count = 0;
        count += helper(nums, s, mid);
        count += helper(nums, mid + 1, e);
        count += merge(nums, s, e);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
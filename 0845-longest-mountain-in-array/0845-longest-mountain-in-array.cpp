class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0), post(n, 0);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                pre[i] = pre[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] > nums[i + 1]) {
                post[i] = post[i + 1] + 1;
            }
        }
        
        int maxi = 0;
        for(int i = 1; i < n - 1; i++) {
            if(pre[i] && post[i])
            maxi = max(maxi, pre[i] + post[i] + 1);
        }
        return maxi;
    }
};
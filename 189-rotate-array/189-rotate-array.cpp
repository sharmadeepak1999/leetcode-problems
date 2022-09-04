class Solution {
public:
    void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         while(k--) {
//             int temp = nums[n - 1];
            
//             int prev = nums[0];
//             for(int i = 1; i < n; i++) {
//                 int temp = nums[i];
//                 nums[i] = prev;
//                 prev = temp;
//             }
            
//             nums[0] = temp;
//         }
        
        
        int n = nums.size();
        k = k % n;
        vector<int> nums1(n - k);
        vector<int> nums2(k);
        for(int i = 0; i < n - k; i++) {
            nums1[i] = nums[i];
        }
        
        for(int i = n - k; i < n; i++) {
            nums2[i - (n - k)] = nums[i];
        }
        
        for(int i = 0; i < k; i++) {
            nums[i] = nums2[i];
        }
        
        for(int i = k; i < n; i++) {
            nums[i] = nums1[i - k];
        }
    }
};
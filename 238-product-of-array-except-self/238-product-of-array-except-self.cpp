class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> p(size);
    
        int lp, rp;
        lp = rp = 1;
        
        for(int i = 0; i < size; i++) {
            p[i] = lp;
            lp *= nums[i];
        }
        for(int i = size - 1;i >= 0; i--) {
            p[i] *= rp;
            rp *= nums[i];
        }
        return p;
    }
};
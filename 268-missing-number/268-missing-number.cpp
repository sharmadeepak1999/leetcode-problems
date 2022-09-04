class Solution {
public:
    int missingNumber(vector<int>& nums) {
//         int x = 0;
//         int n = nums.size();
//         for(int i = 0; i <= n; i++) x ^= i;
        
//         for(auto &a:nums) x^=a;
        
//         return x;
        
        
        int gsum = 0, asum = 0;
        
        for(auto &a:nums) gsum += a;
        int n = nums.size();
        asum = (n * (n + 1)) / 2;
        
        return asum - gsum;
    }
};
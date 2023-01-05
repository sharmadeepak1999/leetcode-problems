class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int asum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int rsum = (n * (n + 1)) / 2;
        return rsum - asum;
    }
};
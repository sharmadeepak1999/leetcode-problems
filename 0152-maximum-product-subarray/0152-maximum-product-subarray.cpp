class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = 1, currMax = 1;
        int ans = *max_element(nums.begin(), nums.end());
        for(auto &n:nums) {
            if(n == 0) {
                currMin = currMax = 1;
            } else {
                int temp = currMax * n;
                currMax = max({currMax * n, currMin * n, n});
                currMin = min({temp, currMin * n, n});
                ans = max(ans, currMax);
            }
        }
        return ans;
    }
};
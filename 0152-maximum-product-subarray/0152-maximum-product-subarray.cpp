class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = 1, currMax = 1;
        int ans = *max_element(nums.begin(), nums.end());
        
        for(auto &num:nums) {
            if(num == 0) {
                currMin = 1, currMax = 1;
            } else {
                int temp = currMax * num;
                currMax = max({ currMax * num, currMin * num, num });
                currMin = min({ temp, currMin * num, num });
                ans = max(ans, currMax);
            }
        }
        return ans;
    }
};
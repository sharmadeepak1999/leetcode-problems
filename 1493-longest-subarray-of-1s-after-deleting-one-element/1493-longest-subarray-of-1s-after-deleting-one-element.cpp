class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int j = 0;
        int lastZero = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                if(lastZero != -1) {
                    if(lastZero > j) j = lastZero + 1;
                    else j++;
                }
                lastZero = i;
            }
            ans = max(ans, i - j);
        }
        return ans;
    }
};
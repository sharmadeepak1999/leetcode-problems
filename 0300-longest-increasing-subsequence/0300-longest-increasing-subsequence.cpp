class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int prevIndex = 0; prevIndex <= n; prevIndex++) {
                if(prevIndex == 0 || nums[prevIndex - 1] < nums[i]) 
                    dp[i][prevIndex] = max(1 + dp[i + 1][i + 1], dp[i + 1][prevIndex]);
                else dp[i][prevIndex] = dp[i + 1][prevIndex];
            }
        }
        return dp[0][0];
    }
};
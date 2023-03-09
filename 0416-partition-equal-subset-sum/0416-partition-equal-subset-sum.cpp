class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int osum = accumulate(nums.begin(), nums.end(), 0);
        if(osum % 2 == 1) return false;
        vector<vector<int>> dp(n, vector<int>(osum / 2 + 1, 0));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= osum / 2; j++) {
                int nottake = dp[i - 1][j];
                int take = 0;
                if(j >= nums[i]) take = dp[i - 1][j - nums[i]];
                dp[i][j] = take or nottake;
            }
        }
        return dp[n - 1][osum / 2];
    }
};
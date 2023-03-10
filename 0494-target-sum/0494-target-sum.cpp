class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if((total - target) < 0 || (total - target) % 2 == 1) return 0;
        int sum = (total - target) / 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        for(int si = 0; si <= sum; si++) {
            if(si == 0 && nums[0] == 0) dp[0][si] = 2;
            else if(si == 0 || nums[0] == si) dp[0][si] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int si = 0; si <= sum; si++) {
                int nottake = dp[i - 1][si];
                int take = 0;
                if(nums[i] <= si) take = dp[i - 1][si - nums[i]];
                dp[i][si] = nottake + take;
            }
        }
        return dp[n - 1][sum];
    }
};
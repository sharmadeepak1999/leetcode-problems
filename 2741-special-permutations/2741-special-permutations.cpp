class Solution {
    int dp[14][16383];
    int mod = 1000000007;
    
    int helper(vector<int> &nums, int i, int &mask) {
        if(mask == (1 << nums.size()) - 1) return 1;

        if(dp[i][mask] != -1) {
            return dp[i][mask];
        }
        int orgMask = mask;
        dp[i][orgMask] = 0;
        for(int j = 0; j < nums.size(); j++) {
            if((mask & (1 << j)) == 0) {
                if(mask == 0 || nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0) {
                    mask |= (1 << j);
                    dp[i][orgMask] = (dp[i][orgMask] + helper(nums, j, mask)) % mod;
                    mask &= ~(1 << j);
                }
            }
        }

        return dp[i][orgMask];
    }
    
public:
    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int mask = 0;
        return helper(nums, 0, mask);
    }
};

class Solution {
    int mod = 1e9 + 7;
    int helper(int low, int high, int zero, int one, vector<int> &dp, int i) {
        if(i >= high + 1) return 0;
        if(dp[i] != -1) return dp[i];
        int pickOne = helper(low, high, zero, one, dp, i + one);
        int pickZero = helper(low, high, zero, one, dp, i + zero);
        
        int curr = 0;
        if(i >= low && i <= high) curr = 1;
        return dp[i] = (curr + pickOne + pickZero) % mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return helper(low, high, zero, one, dp, 0);
    }
};
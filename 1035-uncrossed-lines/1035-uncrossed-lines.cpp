class Solution {
public:
    int helper(vector<int>& nums1, vector<int> &nums2, vector<vector<int>> &dp, int i, int j) {
        if(i <= 0 || j <= 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(nums1[i - 1] == nums2[j - 1]) {
            dp[i][j] = 1 + helper(nums1, nums2, dp, i - 1, j - 1);
        } else {
            dp[i][j] = max(helper(nums1, nums2, dp, i - 1, j), helper(nums1, nums2, dp, i, j - 1));
        }
        return dp[i][j];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(nums1, nums2, dp, m, n);
    }
};
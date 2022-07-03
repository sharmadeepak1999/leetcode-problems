class Solution {
public:
    /*
    int helper(vector<int>& nums, int i, int prevIndex, int prevSign) {
        if(i == nums.size()) {
            return 0;
        }    
        
        if(prevIndex == -1) {
            return max(1 + helper(nums, i + 1, i, -1), helper(nums, i + 1, -1, -1));
        } else {
            int currSign = nums[i] - nums[prevIndex] > 0 ? 1 : 0;
            if((prevSign != -1 && prevSign == currSign) || nums[i] == nums[prevIndex]) {
                return helper(nums, i + 1, prevIndex, prevSign);
            }
           return max(1 + helper(nums, i + 1, i, currSign), helper(nums, i + 1, prevIndex, prevSign));
        }
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        return helper(nums, 0, -1, -1);
    }
    */
    
    int helper(vector<int>& nums, vector<vector<vector<int>>> &dp, int i, int prevIndex, int prevSign) {
        if(i == nums.size()) {
            return 0;
        }    
        
        if(dp[i][prevIndex + 1][prevSign + 1] != -1) return dp[i][prevIndex + 1][prevSign + 1];
        if(prevIndex == -1) {
            return max(1 + helper(nums, dp, i + 1, i, -1), helper(nums, dp, i + 1, -1, -1));
        } else {
            int currSign = nums[i] - nums[prevIndex] > 0 ? 1 : 0;
            if((prevSign != -1 && prevSign == currSign) || nums[i] == nums[prevIndex]) {
                return helper(nums, dp, i + 1, prevIndex, prevSign);
            }
           return dp[i][prevIndex + 1][prevSign + 1] = max(1 + helper(nums, dp, i + 1, i, currSign), helper(nums, dp, i + 1, prevIndex, prevSign));
        }
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        // memoization
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(3, -1)));
        return helper(nums, dp, 0, -1, -1);
    }
};
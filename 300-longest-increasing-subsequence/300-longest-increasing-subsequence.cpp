class Solution {
public:
    /*
    int helper(vector<int>& nums, int i, int lastNum)  {
        if(i < 0) return 0;
        
        if(nums[i] < lastNum) {
            return max(1 + helper(nums, i - 1, nums[i]), helper(nums, i - 1, lastNum));
        } else return helper(nums, i - 1, lastNum);
    }
    int lengthOfLIS(vector<int>& nums) {
        // we can start from the last element in the array, and check if it is smaller than the lastNum which is initially INT_MAX, if yes then we have two choice either to include it in our answer or not, so we will take the max of these cases along with adding a 1 for the take case, if it is not smaller, then we can just skip the element. when the index goes less than 0, we can return 0.
        return helper(nums, nums.size() - 1, INT_MAX);
    }
    */
    
    /*
    int helper(vector<int>& nums, vector<vector<int>> &dp, int i, int lastIndex)  {
        if(i == nums.size()) return 0;
        
        if(dp[i][lastIndex + 1] != -1) return dp[i][lastIndex + 1];
        
        if(lastIndex == -1 || nums[i] > nums[lastIndex]) {
            return dp[i][lastIndex + 1] = max(1 + helper(nums, dp, i + 1, i), helper(nums, dp, i + 1, lastIndex));
        } 
        return dp[i][lastIndex + 1] = helper(nums, dp, i + 1, lastIndex);
    }
    int lengthOfLIS(vector<int>& nums) {
        // we will use memoization, for handling the case for lastIndex to be -1, we can do a coordinate change that is store the result at lastIndex + 1.
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(nums, dp, 0, -1);
    }
    */
    
    /*
    int lengthOfLIS(vector<int>& nums) {
        // we will use tabulation, for handling the case for lastIndex to be -1, we can do a coordinate change that is store the result at lastIndex + 1.
        
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // not necessary
        for(int lastIndex = n - 1; lastIndex >= -1; lastIndex--){
            dp[n][lastIndex + 1] = 0;
        }
        
        for(int i = n - 1; i >= 0; i--) {
            for(int lastIndex = i - 1; lastIndex >= -1; lastIndex--){
                if(lastIndex == -1 || nums[i] > nums[lastIndex]) {
                    dp[i][lastIndex + 1] = max(1 + dp[i + 1][i + 1], dp[i + 1][lastIndex + 1]);
                } else dp[i][lastIndex + 1] = dp[i + 1][lastIndex + 1];
            }
        }
        
        return dp[0][0];
    }
    */
    
    /*
    int lengthOfLIS(vector<int>& nums) {
        // we will space optimize
        int n = nums.size();
        vector<int> front(n + 1, 0), curr(n + 1, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int lastIndex = i - 1; lastIndex >= -1; lastIndex--){
                if(lastIndex == -1 || nums[i] > nums[lastIndex]) {
                    curr[lastIndex + 1] = max(1 + front[i + 1], front[lastIndex + 1]);
                } else curr[lastIndex + 1] = front[lastIndex + 1];
            }
            front = curr;
        }
        
        return front[0];
    }
    
    */
    
    
     int lengthOfLIS(vector<int>& nums) {
        // One approach would be to initialize an array of size nums, with 1 denoting the longest LIS ending with the current index. now start from the first index, and check all the previous indexes, if they are smaller then update current index length to the max of the current and the previous index + 1. also update the maxLen LIS at each index by comparing the current maxLen with the current index value.
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
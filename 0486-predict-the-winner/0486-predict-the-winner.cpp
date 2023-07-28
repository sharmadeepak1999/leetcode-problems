class Solution {
    int helper(vector<int> &nums, int s, int e, int turn, vector<vector<vector<int>>> &dp) {
        if(s > e) return 0;
        if(dp[s][e][turn] != -1) return dp[s][e][turn];
        
        int front = helper(nums, s + 1, e, !turn, dp);
        int back = helper(nums, s, e - 1, !turn, dp);
        
        if(turn == 0) {
            front += nums[s];
            back += nums[e];
            return dp[s][e][turn] = max(front, back);
        } else {
            front -= nums[s];
            back -= nums[e];
            return dp[s][e][turn] = min(front, back);
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int score = helper(nums, 0, nums.size() - 1, 0, dp);
        return score >= 0;
    }
};
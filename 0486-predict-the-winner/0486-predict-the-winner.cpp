class Solution {
    int helper(vector<int> &nums, int s, int e, int turn) {
        if(s > e) return 0;
        
        int front = helper(nums, s + 1, e, !turn);
        int back = helper(nums, s, e - 1, !turn);
        
        if(turn == 0) {
            front += nums[s];
            back += nums[e];
            return max(front, back);
        } else {
            front -= nums[s];
            back -= nums[e];
            return min(front, back);
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int score = helper(nums, 0, nums.size() - 1, 0);
        return score >= 0;
    }
};
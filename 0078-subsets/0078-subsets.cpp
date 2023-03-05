class Solution {
public:
    void helper(int n, int i, vector<int> &nums, vector<vector<int>> &ans, vector<int> sub) {
        if(i == n) {
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        helper(n, i + 1, nums, ans, sub);
        sub.pop_back();
        helper(n, i + 1, nums, ans, sub);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> sub;
        helper(n, 0, nums, ans, sub);
        return ans;
    }
};
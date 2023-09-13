class Solution {
    void helper(vector<int> &nums, int i, vector<vector<int>> &ans, vector<int> &sub) {
        if(i == nums.size()) {
            ans.push_back(sub);
            return;
        }
        
        sub.push_back(nums[i]);
        helper(nums, i + 1, ans, sub);
        sub.pop_back();
        helper(nums, i + 1, ans, sub);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        helper(nums, 0, ans, sub);
        return ans;
    }
};
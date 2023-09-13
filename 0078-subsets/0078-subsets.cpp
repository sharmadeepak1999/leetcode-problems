class Solution {
    void helper(vector<int> &nums, int i, vector<vector<int>> &ans, vector<int> sub) {
        ans.push_back(sub);
        
        for(int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            helper(nums, j + 1, ans, sub);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, 0, ans, {});
        return ans;
    }
};
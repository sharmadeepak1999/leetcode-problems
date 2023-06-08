class Solution {
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr, int i, int n) {
        ans.push_back(curr);
        for(int j = i; j < n; j++) {
            if(j != i && nums[j - 1] == nums[j]) continue;
            curr.push_back(nums[j]);
            helper(nums, ans, curr, j + 1, n);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, ans, curr, 0, nums.size());
        return ans;
    }
};
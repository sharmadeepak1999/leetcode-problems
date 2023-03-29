class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, int i, int n) {
        if(i == n) {
            ans.push_back(nums);
            return;
        }
        for(int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            helper(nums, ans, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        helper(nums, ans, 0, nums.size());
        return ans;
    }
};
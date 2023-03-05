class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> sub, int i, int n) {
        
        ans.push_back(sub);
        
        for(int k = i; k < n; k++) {
            if(k > i && nums[k] == nums[k - 1]) continue;
            
            sub.push_back(nums[k]);
            helper(nums, ans, sub, k + 1, n);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        helper(nums, ans, sub, 0, nums.size());
        return ans;
    }
};
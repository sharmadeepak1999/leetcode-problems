class Solution {
public:
    
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> curr, int i) {
        
        ans.push_back(curr);
        
        for(int j = i; j < nums.size(); j++) {
            if(i != j && nums[j] == nums[j - 1]) continue;
            curr.push_back(nums[j]);
            helper(nums, ans, curr, j + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        helper(nums, ans, {}, 0);
        return ans;
    }
};
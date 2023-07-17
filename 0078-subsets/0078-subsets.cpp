class Solution {
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> sub, int i) {
//         ans.push_back(sub);
        
//         for(int j = i; j < nums.size(); j++) {
//             sub.push_back(nums[j]);
//             helper(nums, ans, sub, j + 1);
//             sub.pop_back();
//         }
        if(i == nums.size()) {
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        helper(nums, ans, sub, i + 1);
        sub.pop_back();
        helper(nums, ans, sub, i + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        helper(nums, ans, {}, 0);
        
        return ans;
    }
};
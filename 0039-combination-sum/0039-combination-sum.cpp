class Solution {
public:
    void helper(vector<int> &candidates, vector<vector<int>> &ans, vector<int> curr, int target, int i) {
        if(i == candidates.size()) {
            if(target == 0) ans.push_back(curr);
            return;
        }
        
        helper(candidates, ans, curr, target, i + 1);
        
        if(candidates[i] <= target) {
            curr.push_back(candidates[i]);
            helper(candidates, ans, curr, target - candidates[i], i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        helper(candidates, ans, {}, target, 0);
        return ans;
    }
};
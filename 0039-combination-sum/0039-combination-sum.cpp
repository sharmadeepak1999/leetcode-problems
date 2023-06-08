class Solution {
    void helper(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &curr, int target, int i, int n) {
        if(target == 0) ans.push_back(curr);
        if(i == n || target <= 0) return;
        
        curr.push_back(candidates[i]);
        helper(candidates, ans, curr, target - candidates[i], i, n);
        curr.pop_back();
        helper(candidates, ans, curr, target, i + 1, n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, ans, curr, target, 0, candidates.size());
        return ans;
    }
};
class Solution {
    void helper(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &sub, int target, int i) {
        if(target == 0) {
            ans.push_back(sub);
            return;
        }
        if(i == candidates.size()) return;
        
        if(candidates[i] <= target) {
            sub.push_back(candidates[i]);
            helper(candidates, ans, sub, target - candidates[i], i);
            sub.pop_back();
        }
        helper(candidates, ans, sub, target, i + 1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        
        helper(candidates, ans, sub, target, 0);
        return ans;
    }
};
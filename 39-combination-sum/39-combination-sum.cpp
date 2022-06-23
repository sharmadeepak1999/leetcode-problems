class Solution {
public:
    void helper(vector<int>& candidates, vector<vector<int>>& res, vector<int> &seq, int index, int target) {
        if(target < 0) return;
        if(index >= candidates.size()) {
            if(target == 0) res.push_back(seq);
            return; 
        }
        seq.push_back(candidates[index]);
        helper(candidates, res, seq, index, target - candidates[index]);
        seq.pop_back();
        helper(candidates, res, seq, index + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> seq;
        helper(candidates, res, seq, 0, target);
        return res;
    }
};
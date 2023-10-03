class Solution {
    void helper(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &curr, int i, int target) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        
        if(target < 0) return;
        for(int j = i; j < candidates.size(); j++) {
            if(j > i && candidates[j] == candidates[j - 1]) continue;
            if(candidates[j] <= target) {
                curr.push_back(candidates[j]);
                helper(candidates, ans, curr, j + 1, target - candidates[j]);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, ans, curr, 0, target);
        return ans;
    }
};
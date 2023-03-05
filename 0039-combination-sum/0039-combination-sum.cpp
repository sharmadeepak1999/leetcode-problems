class Solution {
public:
    void helper(vector<int> &candidates, vector<vector<int>> &ans, vector<int> sub, int target, int i, int n, int sum) {
        if(sum > target) return;
        if(i == n) {
            if(sum == target) {
                ans.push_back(sub);
            }
            return;
        }
        sub.push_back(candidates[i]);
        helper(candidates, ans, sub, target, i, n, sum + candidates[i]);
        
        sub.pop_back();
        helper(candidates, ans, sub, target, i + 1, n, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> sub;
        helper(candidates, ans, sub, target, 0, n, 0);
        return ans;
    }
};
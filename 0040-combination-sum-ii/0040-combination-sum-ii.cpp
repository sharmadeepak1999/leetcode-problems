class Solution {
public:
//     void helper(vector<int> &candidates, set<vector<int>> &s, vector<int> sub, int target, int i) {
//         if(i == candidates.size()) {
//             if(target == 0) {
//                 sort(sub.begin(), sub.end());
//                 s.insert(sub);
//             }
//             return;
//         }
//         if(candidates[i] <= target) {
//             sub.push_back(candidates[i]);
//             helper(candidates, s, sub, target - candidates[i], i + 1);
//             sub.pop_back();
//         }
        
//         helper(candidates, s, sub, target, i + 1);
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         set<vector<int>> s;
//         vector<int> sub;
//         helper(candidates, s, sub, target, 0);
        
//         vector<vector<int>> ans;
        
//         for(auto &it:s) {
//             ans.push_back(it);
//         }
//         return ans;
//     }
    
    
    
    void helper(vector<int> &candidates, vector<vector<int>> &ans, vector<int> sub, int target, int i) {
        if(target == 0) ans.push_back(sub);
        else {
            for(int k = i; k < candidates.size(); k++) {
                if(k > i && candidates[k] == candidates[k - 1]) continue;
                
                if(candidates[k] > target) break;
                
                sub.push_back(candidates[k]);
                helper(candidates, ans, sub, target - candidates[k], k + 1);
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        helper(candidates, ans, sub, target, 0);
        return ans;
    }
};
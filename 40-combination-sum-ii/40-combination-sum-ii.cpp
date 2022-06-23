class Solution {
public:
    // void helper(int index, int target, vector<int>& candidates, vector<int>& seq, set<vector<int>>& res) {
    //     if(index >= candidates.size()) {
    //         if(target == 0) {
    //             if(res.find(seq) == res.end()) {
    //                 res.insert(seq);
    //             }
    //         };
    //         return;
    //     }
    //     if(candidates[index] <= target) {
    //         seq.push_back(candidates[index]);
    //         helper(index + 1, target - candidates[index], candidates, seq, res);
    //         seq.pop_back();   
    //     }
    //     helper(index + 1, target, candidates, seq, res);
    // }
    
    
    void helper(int index, int target, vector<int>& candidates, vector<int>& seq, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(seq);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            
            seq.push_back(candidates[i]);
            helper(i + 1, target - candidates[i], candidates, seq, res);
            seq.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*
        // A brute force appraoch is to use a set, and store the seq in the set, and before inserting new sequence check if it already exists in the set, for the recursion do two calls, one with picking current element, one with excluding. and before returning the result convert the set back into vector and return. also before calling the recursive function sort the array.
        
        set<vector<int>> res;
        vector<int> seq;
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates, seq, res);
        vector<vector<int>> ans;
        
        for(auto &seq : res) {
            ans.push_back(seq);
        }
        return ans;
        */
        
        vector<vector<int>> res;
        vector<int> seq;
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates, seq, res);
        return res;
    }
};
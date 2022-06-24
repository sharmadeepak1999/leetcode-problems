class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& per, unordered_set<int> &s) {
        if(per.size() == nums.size()) {
            ans.push_back(per);
            return;
        }
        for(int j = 0; j < nums.size(); j++) {
            if(s.find(j) != s.end()) continue;
            per.push_back(nums[j]);
            s.insert(j);
            helper(nums, ans, per, s);
            per.pop_back();
            s.erase(j);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> per;
        unordered_set<int> s;
        helper(nums, ans, per, s);
        return ans;
    }
};
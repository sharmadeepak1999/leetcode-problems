class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& sub, int n, int k, int i) {
        if(k == sub.size()) {
            ans.push_back(sub);
            return;
        }
        
        for(int j = i; j <= n; j++) {
            sub.push_back(j);
            helper(ans, sub, n, k, j + 1);
            sub.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sub;
        
        helper(ans, sub, n, k, 1);
        return ans;
    }
};


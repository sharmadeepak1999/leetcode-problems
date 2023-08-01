class Solution {
    void helper(vector<vector<int>> &ans, vector<int> &curr, int n, int k) {
        if(k == 0) {
            ans.push_back(curr);
            return;
        }
        if(n == 0) return;
        
        curr.push_back(n);
        helper(ans, curr, n - 1, k - 1);
        curr.pop_back();
        helper(ans, curr, n - 1, k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, curr, n, k);
        return ans;
    }
};
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
        // We will fix a number from the range and call recursion on it, we will do this for all the number in the range using a for loop, if the size of the subset becomes equal to the k, then we push the current subset into ans, and return. also after the recursion call returns we pop out the last element from the subset that we have previously added.
        
        vector<vector<int>> ans;
        vector<int> sub;
        
        helper(ans, sub, n, k, 1);
        return ans;
    }
};


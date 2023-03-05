class Solution {
public:
    void helper(int n, int o, string s, vector<string> &ans) {
        if(n == 0) {
            ans.push_back(s);
            return;
        }
        if(o == 0) {
            helper(n, o + 1, s + '(', ans);
        } else {
            if(o < n)
                helper(n, o + 1, s + '(', ans);
            helper(n - 1, o - 1, s + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, 0, "", ans);
        return ans;
    }
};
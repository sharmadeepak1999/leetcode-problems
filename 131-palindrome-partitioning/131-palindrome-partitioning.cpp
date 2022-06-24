class Solution {
public:
    void helper(string s, vector<vector<string>>& ans, vector<string>& part, int i, int n) {
        if(i == n) {
            ans.push_back(part);
            return;
        }
        string sub = "";
        for(int j = i; j < n; j++) {
            sub += s[j];
            string rev = sub;
            reverse(rev.begin(), rev.end());
            if(rev == sub) {
                part.push_back(sub);
                helper(s, ans, part, j + 1, n);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        helper(s, ans, part, 0, s.length());
        return ans;
    }
};
class Solution {
public:
    void helper(string s, vector<vector<string>> &ans, vector<string> curr, string str, int i) {
        if(i == s.length()) {
            if(str != "")
            curr.push_back(str);
            
            bool f = true;
            
            for(auto &st:curr) {
                string temp = st;
                reverse(temp.begin(), temp.end());
                if(temp != st) {
                    f = false;
                    break;
                }
            }
            if(f) ans.push_back(curr);
            return;
        }
        if(str != "") {
            curr.push_back(str);
            helper(s, ans, curr, "", i);
            curr.pop_back();
        }
        helper(s, ans, curr, str + s[i], i + 1);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        string str = "";
        helper(s, ans, curr, str, 0);
        return ans;
    }
};
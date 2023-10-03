class Solution {
    bool isPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
    void helper(string s, vector<vector<string>> &ans, vector<string> &curr, int i) {
        if(i == s.length()) {
            ans.push_back(curr);
            return;
        }
        for(int j = i; j < s.length(); j++) {
            if(isPalindrome(s.substr(i, j - i + 1))) {
                curr.push_back(s.substr(i, j - i + 1));
                helper(s, ans, curr, j + 1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(s, ans, curr, 0);
        return ans;
    }
};
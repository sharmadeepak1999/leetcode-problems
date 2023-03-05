class Solution {
public:
    void helper(string digits, vector<string> &mp, vector<string> &ans, string s, int i) {
        if(i == digits.size()) {
            ans.push_back(s);
            return;
        }
        
        for(int k = 0; k < mp[digits[i] - '0'].size(); k++) {
            helper(digits, mp, ans, s + mp[digits[i] - '0'][k], i + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        
        helper(digits, mp, ans, "", 0);
        
        return ans;
    }
};
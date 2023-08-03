class Solution {
    void helper(string digits, int i, unordered_map<int, string> &mp, vector<string> &ans, string curr) {
        if(i == digits.size()) {
            if(curr.size())
            ans.push_back(curr);
            return;
        }
        for(auto &c:mp[digits[i] - '0']) {
            helper(digits, i + 1, mp, ans, curr + c);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp{{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        vector<string> ans;
        helper(digits, 0, mp, ans, "");
        return ans;
    }
};
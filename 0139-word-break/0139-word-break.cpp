class Solution {
    bool helper(string &s, unordered_set<string> &st, int i, vector<int> &dp) {
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < s.size(); j++) {
            string sub = s.substr(i, j - i + 1);
            if(st.find(sub) != st.end()) {
                if(helper(s, st, j + 1, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto &str:wordDict) st.insert(str);
        vector<int> dp(s.size() + 1, -1);
        return helper(s, st, 0, dp);
    }
};
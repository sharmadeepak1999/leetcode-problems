class Solution {
public:
    void helper(string s, string curr, int i, vector<vector<string>> &ans, vector<string> currPart) {
        if(i == s.size()) {
            string orgS = "";
            for(auto &part:currPart) orgS += part;
            
            if(orgS == s) {
                ans.push_back(currPart);
            }
            return;
        }
        curr += s[i];
        string revcurr = curr;
        reverse(revcurr.begin(), revcurr.end());
        
        if(curr == revcurr) {
            currPart.push_back(curr);
            helper(s, "", i + 1, ans, currPart);
            currPart.pop_back();
        }
        helper(s, curr, i + 1, ans, currPart);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currPart;
        
        helper(s, "", 0, ans, currPart);
        return ans;
    }
};
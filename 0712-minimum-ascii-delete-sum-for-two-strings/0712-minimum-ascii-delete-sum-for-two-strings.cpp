class Solution {
    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if(i == s1.size() && j == s2.size()) return 0;
        if(i == s1.size()) {
            int sum = 0;
            
            for(int k = j; k < s2.size(); k++) sum += int(s2[k]);
            return sum;
        }
        if(j == s2.size()) {
            int sum = 0;
            
            for(int k = i; k < s1.size(); k++) sum += int(s1[k]);
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) {
            return dp[i][j] = helper(s1, s2, i + 1, j + 1, dp);
        }
        
        return dp[i][j] = min(int(s1[i]) + helper(s1, s2, i + 1, j, dp), int(s2[j]) + helper(s1, s2, i, j + 1, dp));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return helper(s1, s2, 0, 0, dp);        
    }
};
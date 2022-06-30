class Solution {
public:
    /*
    int helper(string text1, string text2, int i1, int i2) {
        if(i1 < 0 || i2 < 0) return 0;
        
        if(text1[i1] == text2[i2]) return 1 + helper(text1, text2, i1 - 1, i2 - 1);
        else return max(helper(text1, text2, i1 - 1, i2), helper(text1, text2, i1, i2 - 1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // A brute force way would be to compute all the subsequences of both the strings, and then compare them one by one to get the longest matching subsequences.
        
        // a better way would be to start from the end of the both  string, if the last char matches then we call recursion on the next char of both the strings along with adding a one to current char result, if they are not equal, then we will once decrease first string pointer, and once decresase the other string pointer, and get the max of both and return.
        
        return helper(text1, text2, text1.size() - 1, text2.size());
    }
    */
    
    
    /*
    int helper(string text1, string text2, vector<vector<int>> &dp, int i1, int i2) {
        if(i1 == 0 || i2 == 0) return 0;
        
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(text1[i1 - 1] == text2[i2 - 1]) return 1 + helper(text1, text2, dp, i1 - 1, i2 - 1);
        return dp[i1][i2] = max(helper(text1, text2, dp, i1 - 1, i2), helper(text1, text2, dp, i1, i2 - 1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // we will use memoization to time optimize
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        
        return helper(text1, text2, dp, text1.size(), text2.size());
    }
    */

    /*
    int longestCommonSubsequence(string text1, string text2) {
        // we will space optimize using only two 1D array
        vector<int> prev(text2.size() + 1, 0), curr(text2.size() + 1, 0);
        
        prev[0] = curr[0] = 0;
        
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[text2.size()];
    }
    */
    
    
    
    int longestCommonSubsequence(string text1, string text2) {
        // Printing the LCS
        vector<int> prev(text2.size() + 1, 0), curr(text2.size() + 1, 0);
        
        prev[0] = curr[0] = 0;
        
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        
        string lcs = "";
        
        int i = text1.size(), j = text2.size();
        
        while(i > 0 && j > 0) {
            if(text1[i - 1] == text2[j - 1]) {
                lcs = text1[i - 1] + lcs;
                i--;
                j--;
            } else if(prev[j] > curr[j - 1]) {
                i--;
            } else j--;
        }
        
        cout << lcs << endl;
        
        return prev[text2.size()];
    }
};
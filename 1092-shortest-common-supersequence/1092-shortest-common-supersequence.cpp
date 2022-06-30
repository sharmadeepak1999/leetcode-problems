class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // For the length of the shortest common subsequence, we can say that we will include the longest common subsequence of both strings only once in the answer, and the other characters, will be added as it is, so we can denote the shortes common subsequence length to be as len(str1) + len(str2) - len(lcs), this is because the lcs would be present in both the strings, but we have to count it only once so subtracting it once from the sum of len of both the strins.
        
        // now for printing the scs, we will use the dp array in the tabulation method, we will traverse the dp array from the back, and if char at that indexes in both the strings are equal then we will add it once in our scs string, and move to diagonally to the next indexes in both strings, if they are not equal then we will move to either the upper row, or we will move to the left column, depends which one of these cell value is bigger.
        
        vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
        
        for(int i = 0; i <= str1.length(); i++) dp[i][0] = 0;
        for(int j = 0; j <= str2.length(); j++) dp[0][j] = 0;
        
        for(int i = 1; i <= str1.length(); i++) {
            for(int j = 1; j <= str2.length(); j++) {
                if(str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        int i = str1.length(), j = str2.length();
        
        string scs = "";
        
        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                scs = str1[i - 1] + scs;
                i--;
                j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                scs = str1[i - 1] + scs;
                i--;
            } else {
                scs = str2[j - 1] + scs;
                j--;
            }
        }
        while(i > 0) {
            scs = str1[i - 1] + scs;
            i--;
        }
        
        while(j > 0) {
            scs = str2[j - 1] + scs;
            j--;
        }
        return scs;
    }
};
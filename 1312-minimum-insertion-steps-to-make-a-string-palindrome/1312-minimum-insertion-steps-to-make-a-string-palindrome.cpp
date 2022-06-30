class Solution {
public:
    int longestPalindromicSubsequence(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        vector<int> prev(s.length() + 1, 0), curr(s.length() + 1, 0);
        prev[0] = curr[0] = 0;
        
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= rs.length(); j++) {
                if(s[i - 1] == rs[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[rs.length()];
    }
    int minInsertions(string s) {
        // The idea is that we have the longest palindromic subsequence intact and we copy paste the other chars in order to make the whole string palindrome, so the minimum number of operation that would be required would be the length of the string - length of the longest common subsequence, because this represnt the no. of chars that need to be copy pasted in the string at different location to make the string palindrome.
        
        return s.length() - longestPalindromicSubsequence(s);
    }
};
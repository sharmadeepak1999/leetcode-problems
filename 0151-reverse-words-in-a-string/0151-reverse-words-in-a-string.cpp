class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = s.length() - 1;
        
        while(s[i] == ' ') i++;
        while(s[j] == ' ') j--;
        
        string ans = "";
        while(i <= j) {
            string word = "";
            while(i <= j && s[i] != ' ') word += s[i++];
            while(i <= j && s[i] == ' ') i++;
            reverse(word.begin(), word.end());
            ans += word;
            if(i <= j)
                ans += ' ';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
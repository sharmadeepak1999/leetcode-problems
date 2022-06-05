class Solution {
public:
    bool helper(string& str, int s, int e, int delcount) {
        if(s > e) return true;
        if(delcount > 1) return false;
        if(str[s] == str[e]) {
            return helper(str, s + 1, e - 1, delcount);
        } else {
            delcount++;
            return helper(str, s + 1, e, delcount) || helper(str, s, e - 1, delcount);
        }
        return false;
    }
    bool validPalindrome(string s) {
        return helper(s, 0, s.length() - 1, 0);
    }
};
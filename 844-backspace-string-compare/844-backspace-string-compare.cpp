class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Process each string, insert into a new string if it is not #, else delete the last inserted char from the new string variable. do the same for the other string too. at last compare both the new string formed if equal return true. basically we are using the new string variable as a stack.
        // The other approach would be to use a stack itself instead of string.

        string s1 = "";
        
        for(auto &c : s) {
            if(c == '#' && s1.size()) s1.pop_back();
            else if(c != '#') s1.push_back(c);
        }
        string s2 = "";
        
        for(auto &c : t) {
            if(c == '#' && s2.size()) s2.pop_back();
            else if(c != '#') s2.push_back(c);
        }
        return s1 == s2;        
    }
};
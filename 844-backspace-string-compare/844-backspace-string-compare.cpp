class Solution {
public:
    bool backspaceCompare(string s, string t) {
        /*
        // Process each string, insert into a new string if it is not #, else delete the last inserted char from the new string variable. do the same for the other string too. at last compare both the new string formed if equal return true. basically we are using the new string variable as a stack.
        // The other approach would be to use a stack itself instead of string. both these would be O(n) space.

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
        */
        
        int i = s.length() - 1;
        int j = t.length() - 1;
        
        
        while(i >= 0 || j >= 0) {
            int count = 0;
            while(i >= 0 && (count > 0 || s[i] == '#')) {
                if(s[i] == '#') count++;
                else count--;
                i--;
            }
            count = 0;
            while(j >= 0 && (count > 0 || t[j] == '#')) {
                if(t[j] == '#') count++;
                else count--;
                j--;
            }
            
            if(i >= 0 && j >= 0) {
                if(s[i] != t[j]) return false;
                else {
                    i--;
                    j--;
                }
            } else if(i >= 0 || j >= 0) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool backspaceCompare(string s, string t) {
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
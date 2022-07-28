class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        
        for(auto &c:s) m[c]++;
        
        for(auto &c:t) {
            if(m.find(c) == m.end()) return false;
            m[c]--;
            if(m[c] == 0) m.erase(c);
        }
        return m.size() == 0;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> mp;
        
        for(auto &ch:s) mp[ch]++;
        
        for(auto &ch:t) {
            if(!mp.count(ch)) return false;
            mp[ch]--;
            if(mp[ch] == 0) mp.erase(ch);
        }
        return true;
    }
};
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        
        for(auto &c:s) mp[c]++;
        
        for(int i = 0; i < n; i++) {
            if(mp[s[i]] == 1) return i;
        }
        return -1;
    }
};
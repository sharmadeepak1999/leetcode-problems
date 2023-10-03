class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> s1Map(26, 0), s2Map(26, 0);
        int k = s1.size();
        
        for(int i = 0; i < k; i++) {
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }
        
        if(s1Map == s2Map) return true;
        
        for(int i = k; i < s2.length(); i++) {
            s2Map[s2[i - k] - 'a']--;
            s2Map[s2[i] - 'a']++;
            if(s1Map == s2Map) return true;
        }
        return false;
    }
};
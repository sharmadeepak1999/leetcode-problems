class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto &n:nums) s.insert(n);
        
        int lcs = 0;
        
        for(auto &n:s) {
            int clcs = 1;
            int i = 1;
            while(s.find(n - i) != s.end()) {
                s.erase(n - i);
                i++;
                clcs++;
            }
            i = 1;
            while(s.find(n + i) != s.end()) {
                s.erase(n + i);
                i++;
                clcs++;
            }
            
            lcs = max(lcs, clcs);
        }
        return lcs;
    }
};
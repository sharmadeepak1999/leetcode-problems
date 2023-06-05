class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &num:nums) s.insert(num);
        int lcs = 0;
        while(!s.empty()) {
            int el = *s.begin();
            s.erase(el);
            int curr = 1;
            int temp = el;
            while(s.find(--temp) != s.end()) {
                curr++;
                s.erase(temp);
            }
            temp = el;
            while(s.find(++temp) != s.end()) {
                curr++;
                s.erase(temp);
            }
            
            lcs = max(lcs, curr);
        }
        return lcs;
    }
};
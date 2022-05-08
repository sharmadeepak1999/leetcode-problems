class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto n : nums) {
            if(s.find(n) != s.end()) {
                return n;
            }
            s.insert(n);
        }
        return -1;
    }
};
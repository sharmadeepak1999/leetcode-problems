class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_multiset<int> s;
        for(auto &num:nums) s.insert(num);
        
        int maxi = 0;
        for(auto &num:nums) {
            if(s.find(num - 1) == s.end()) {
                int l = 0;
                while(s.find(num) != s.end()) l++, num++;
                maxi = max(maxi, l);
            }
        }
        return maxi;
    }
};
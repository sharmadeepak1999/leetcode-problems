class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto &num:nums) s.insert(num);
        int maxi = 0;
        for(auto &num:s) {
            int left = -1, right = 1;
            int count = 1;
            while(s.find(num + left) != s.end()) {
                count++;
                s.erase(num + left);
                left--;
            } 
            while(s.find(num + right) != s.end()) {
                count++;
                s.erase(num + right);
                right++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        vector<int> ans;
        for(auto x : nums1) {
            if(hashmap.find(x) == hashmap.end()) {
                hashmap[x] = 1;
            }
        }
        
        for(auto x : nums2) {
            if(hashmap.find(x) != hashmap.end()) {
                ans.push_back(x);
                hashmap.erase(x);
            }
        }
        return ans;
    }
};
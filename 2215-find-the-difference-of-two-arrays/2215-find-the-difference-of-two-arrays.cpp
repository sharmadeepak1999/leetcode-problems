class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mp1, mp2;
        for(auto &num:nums1) mp1.insert(num);
        for(auto &num:nums2) mp2.insert(num);
        
        vector<int> ans1, ans2;
        
        for(auto &it:mp1) {
            if(mp2.count(it) == 0) ans1.push_back(it);
        }
                
        for(auto &it:mp2) {
            if(mp1.count(it) == 0) ans2.push_back(it);
        }
        return { ans1, ans2 };
    }
};
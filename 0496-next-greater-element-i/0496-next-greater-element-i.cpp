class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        
        s.push(-1);
        
        unordered_map<int, int> mp;
        int n = nums2.size();
        for(int i = n - 1; i >= 0; i--) {
            while(nums2[i] > s.top() && s.top() != -1) s.pop();
            
            mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        
        for(auto &num:nums1) ans.push_back(mp[num]);
        return ans;
    }
};
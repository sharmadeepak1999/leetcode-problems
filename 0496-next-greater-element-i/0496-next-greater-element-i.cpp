class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        st.push(-1);
        unordered_map<int, int> mp;
        int n2 = nums2.size();
        for(int i = n2 - 1; i >= 0; i--) {
            while(st.top() != -1 && st.top() < nums2[i]) {
                st.pop();
            }
            mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        
        vector<int> ans;
        
        for(auto &num:nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};
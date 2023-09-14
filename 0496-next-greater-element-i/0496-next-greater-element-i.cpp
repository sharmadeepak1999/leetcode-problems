class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> t(n2, -1);
        
        stack<int> st;
        st.push(-1);
        
        for(int i = n2 - 1; i >= 0; i--) {
            while(st.size() && st.top() != -1 && st.top() < nums2[i]) st.pop();
            t[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto &num1:nums1) {
            for(int i = 0; i < n2; i++) {
                if(nums2[i] == num1) {
                    ans.push_back(t[i]);
                }
            }
        }
        return ans;
    }
};
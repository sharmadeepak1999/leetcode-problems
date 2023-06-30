class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st;
        
        for(auto &num:nums) st.insert(num);
        int lss = -1;
        for(auto &num:nums) {
            if(st.find(sqrt(num)) == st.end()) {
                int css = 1;
                int a = num;
                st.erase(a);
                while(st.find((long long) a * a) != st.end()) {
                    css++;
                    st.erase(a * a);
                    a = a * a;
                }
                if(css >= 2) lss = max(lss, css);
            }
        }
        return lss;
    }
};
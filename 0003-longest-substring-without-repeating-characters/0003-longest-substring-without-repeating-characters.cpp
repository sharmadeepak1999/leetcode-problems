class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        unordered_set<char> st;
        int i = 0;
        int maxi = 0;
        st.insert(s[0]);
        for(int k = 1; k < s.length(); k++) {
            if(st.find(s[k]) != st.end()) {
                while(s[i] != s[k]) {
                    st.erase(s[i]);
                    i++;
                }
                i++;
            } else st.insert(s[k]);
            
            maxi = max(maxi, k - i);
        }
        return maxi + 1;
    }
};
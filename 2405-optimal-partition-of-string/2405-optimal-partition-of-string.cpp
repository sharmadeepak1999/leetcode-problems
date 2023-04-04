class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        
        int count = 0;
        
        for(auto &c:s) {
            if(st.find(c) != st.end()) {
                count++;
                st.clear();
                st.insert(c);
            } else st.insert(c);
        }
        if(st.size()) count++;
        return count;
    }
};
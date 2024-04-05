class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for(auto &ch:s) {
            if(st.empty() || (abs(st.top() - ch) != 32)) st.push(ch);
            else {
                st.pop();
            }
        }
        
        string res = "";
        while(st.size()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
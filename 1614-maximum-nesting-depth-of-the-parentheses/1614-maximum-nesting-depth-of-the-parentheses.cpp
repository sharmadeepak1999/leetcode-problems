class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int res = 0;
        for(auto &ch:s) {
            if(ch == '(') {
                st.push('(');
            } else if(ch == ')') {
                st.pop();
            }
            res = max(res, (int)st.size());
        }
        return res;
    }
};
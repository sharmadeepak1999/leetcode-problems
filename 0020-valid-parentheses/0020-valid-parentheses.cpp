class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto &ch:s) {
            if(ch == ']' || ch == '}' || ch == ')') {
                if(st.empty()) return false;
                char top = st.top();
                if(!((top == '[' && ch == ']') || (top == '{' && ch == '}') || (top == '(' && ch == ')'))) return false;
                st.pop();
            } else st.push(ch);
        }
        return st.empty();
    }
};
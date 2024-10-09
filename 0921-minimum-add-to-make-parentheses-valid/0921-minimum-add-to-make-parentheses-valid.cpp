class Solution {
public:
    int minAddToMakeValid(string s) {
        int o = 0, c = 0;
        
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else st.push(')');
            } else st.push(s[i]);
        }
        return st.size();
    }
};
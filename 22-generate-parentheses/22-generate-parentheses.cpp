class Solution {
public:
    void helper(vector<string> &v, string str, int s, int e) {
        cout << endl << str;
        if(e == 0) return v.push_back(str);
        if(str.empty()) 
            helper(v, str + '(', s - 1, e);
        else {
            if(s > 0) helper(v, str + '(', s - 1, e);
            if(s != e) helper(v, str + ')', s, e - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        helper(s, "", n, n);
        return s;
    }
};
class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[') v.push_back(c);
            else if(v.empty() || (c == ')' && v.back() != '(') || (c == ']' && v.back() != '[') || (c == '}' && v.back() != '{')) return false;
            else v.pop_back();
        }
        
        return v.empty();
    }
};
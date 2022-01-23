class Solution {
public:
    string addBinary(string a, string b) {
        int sum = 0, carry = 0;
        string ans;
        while(a.size() || b.size()) {
            int o1 = 0, o2 = 0;
            if(a.size() > 0) {
                o1 = a.back() - '0';
                a.pop_back();
            }
            if(b.size() > 0) {
                o2 = b.back() - '0';
                b.pop_back();
            }
            sum = o1 + o2 + carry;
            ans = to_string(sum % 2) + ans;
            carry = sum / 2;
        }
        if(carry) ans = to_string(carry) + ans;
        return ans;
    }
};
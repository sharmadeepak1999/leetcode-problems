class Solution {
public:
    int convert(string s, int i, int n, int sign) {
        if(i == n) return 0;
        
        int res = convert(s, i + 1, n, sign);
        if(res == INT_MAX || res == INT_MIN) return res;

        if(res > INT_MAX / 10 || (res == (INT_MAX / 10) && s[i] - '0' > 7)) {
            if(sign == -1) return INT_MIN;
            return INT_MAX;
        }
        
        return res * 10 + (s[i] - '0');
    }
    int myAtoi(string s) {
        string trimmed = "";
        int n = s.length();
        
        int i = 0;
        bool f = true;
        while(i < n) {
            if(s[i] != ' ' || !f) {
                f = false;
                trimmed += s[i];
            }
            i++;
        }
        
        n = trimmed.length();
        i = 0;
        int sign = 1;
        if(trimmed[i] == '-') {
            sign = -1;
            i++;
        } else if(trimmed[i] == '+') {
            i++;
        }
        
        string num = "";

        while(i < n && trimmed[i] >= '0' && trimmed[i] <= '9') {
            num += trimmed[i];
            i++;
        }
        reverse(num.begin(), num.end());
        int converted = convert(num, 0, num.size(), sign);
        if(converted == INT_MAX && sign == -1) return INT_MIN + 1;
        if(converted == INT_MAX || converted == INT_MIN) return converted;
        return converted * sign;
    }
};
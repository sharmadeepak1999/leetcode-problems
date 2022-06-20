class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int carry = 0;
        
        int ea = a.size() - 1, eb = b.size() - 1;
        
        while(ea >= 0 && eb >= 0) {
            int oa = a[ea--] - '0';
            int ob = b[eb--] - '0';
            
            int s = oa + ob + carry;
            sum = to_string(s%2) + sum;
            carry = s / 2;
        }
    
        while(ea >= 0) {
            int oa = a[ea--] - '0';
            
            int s = oa + carry;
            sum = to_string(s%2) + sum;
            carry = s / 2;
        }
    
        while(eb >= 0) {
            int ob = b[eb--] - '0';
            
            int s = ob + carry;
            sum = to_string(s%2) + sum;
            carry = s / 2;
        }
        
        if(carry) sum = '1' + sum;
        return sum;
    }
};
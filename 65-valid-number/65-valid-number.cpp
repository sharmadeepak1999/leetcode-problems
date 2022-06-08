class Solution {
public:
    bool isDecimal(string s) {
        if(s.length() == 0) return false;
        bool hasSign = false;
        if(s[0] == '+' || s[0] == '-') {
            hasSign = true; 
            s = s.substr(1);
        }
        
        bool decimalFound = false;
        string s1 = "", s2 = "";
        for(auto &c:s){
            if(c == '.') {
                if(decimalFound) return false;
                else decimalFound = true;
            } else if(isdigit(c)){
                if(!decimalFound) s1 += c;
                else s2 += c;
            } else return false;
        }
        
        if(!decimalFound || (s2.length() == 0 && s1.length() == 0)) return false;
        return true;
    }
    
    
    bool isInteger(string s) {
        if(s.length() == 0) return false;
        
        bool hasSign = false;
        if(s[0] == '+' || s[0] == '-') {
            hasSign = true; 
            s = s.substr(1);
        }
        if(s.length() == 0) return false;
        for(auto &c:s){
            if(!isdigit(c)) return false;
        }
        return true;
    }
    
    bool isNumber(string s) {
        string s1 = "", s2 = "";
        bool expoFound = false;
        for(auto &c:s) {
            if((c == 'e' || c == 'E') && !expoFound) {
             expoFound = true;   
                continue;
            }
            
            if(expoFound) s2 += c;
            else s1 += c;
        }
        return expoFound ? (isDecimal(s1) || isInteger(s1)) && isInteger(s2) : (isDecimal(s1) || isInteger(s1));
    }
};
class Solution {
public:
    string reverseWords(string s) {
        string rs = "";
        
        int i = 0;
        string w = "";
        while(i < s.length()) {
            if(w == "" && s[i] == ' ') {
              i++;
              continue;  
            } 
            if(s[i] == ' '){
             rs = ' ' + w + rs;   
             w = "";
            } else w += s[i];
            i++;
        }
        if(w != "") rs = w + rs;
        else rs = rs.substr(1);
        return rs;
    }
};
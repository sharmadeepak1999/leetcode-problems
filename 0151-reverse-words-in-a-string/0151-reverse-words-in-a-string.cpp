class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        
        int i = 0, j = n - 1;
        
        while(i < n && s[i] == ' ') i++;
        while(j >= 0 && s[j] == ' ') j--;
        
        string ns = "";
        
        while(i <= j) {
            if(s[i] == ' ') {
                if(ns[ns.length() - 1] != ' ') ns += ' ';
            } else ns += s[i];
            
            i++;
        }
        
        i = 0, j = ns.length();
        
        while(i <= j) {
            int st = i;
            
            while(i <= j && ns[i] != ' ') i++;
            if(i > j) 
                reverse(ns.begin() + st, ns.end());
            else reverse(ns.begin() + st, ns.begin() + i);

            i++;
        }
        reverse(ns.begin(), ns.end());
        return ns;
    }
};
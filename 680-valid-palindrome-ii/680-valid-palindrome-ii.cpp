class Solution {
public:
    /*
    bool helper(string& str, int s, int e, int delcount) {
        // We can use an recursive approach, we will place a start and end pointer, and check if char at these pointer is equal, if yes then call recursively by shifting the start and end pointer, if not equal then either delete the first or last char, also increase a delete counter, the base case of recursive call is either start pointer greater than end, or the del count of char is greater than 1.
        
        if(s > e) return true;
        if(delcount > 1) return false;
        if(str[s] == str[e]) {
            return helper(str, s + 1, e - 1, delcount);
        } else {
            delcount++;
            return helper(str, s + 1, e, delcount) || helper(str, s, e - 1, delcount);
        }
        return false;
    }
    
    */
    
    
    bool validPalindrome(string s) {
        // return helper(s, 0, s.length() - 1, 0);
        
        
        for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if(s[i] != s[j]) {
                int i1 = i, j1 = j - 1;
                while(s[i1] == s[j1] && i1 < j1) {
                    i1++;
                    j1--;
                }
                if(i1 >= j1) return true;
                
                int i2 = i + 1, j2 = j;
                
                while(s[i2] == s[j2] && i2 < j2) {
                    i2++;
                    j2--;
                }
                return i2 >= j2;
            }
        }
        return true;
    }
};
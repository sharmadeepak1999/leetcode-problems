class Solution {
public:
    int takeCharacters(string s, int k) {
        if(3 * k > s.size()) return -1;
        
        int ca, cb, cc;
        ca = cb = cc = 0;
        
        for(auto &ch:s) {
            if(ch == 'a') ca++;
            if(ch == 'b') cb++;
            if(ch == 'c') cc++;
        }
        
        if(ca < k || cb < k || cc < k) return -1;
        int n = s.size();
        int i = n - 1, j = n - 1;
        int ans = INT_MAX;
        while(i >= 0) {
            if(s[i] == 'a') ca--;
            if(s[i] == 'b') cb--;
            if(s[i] == 'c') cc--;
            
            while(ca < k || cb < k || cc < k) {
                if(s[j] == 'a') ca++;
                if(s[j] == 'b') cb++;
                if(s[j] == 'c') cc++;
                j--;
            }
            
            ans = min(ans, i + (n - j - 1));
            i--;
        }
        return ans;
    }
};
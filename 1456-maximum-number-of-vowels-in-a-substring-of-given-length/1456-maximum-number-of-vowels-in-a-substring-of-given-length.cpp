class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int maxi = 0;
        int curr = 0;
        int n = s.length();
        for(int i = 0; i < k; i++) {
            if(isVowel(s[i])) curr++;
        }
        maxi = max(maxi, curr);
        
        int i = 0, j = k - 1;
        
        while(j < n) {
            if(isVowel(s[i])) curr--;
            i++;
            j++;
            if(isVowel(s[j])) curr++;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};
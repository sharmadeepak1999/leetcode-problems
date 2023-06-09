class Solution {
    string nextPermutation(string s) {
        int j = -1;
        int n = s.length();
        for(int i = n - 1; i >= 1; i--) {
            if(s[i - 1] < s[i]) {
                j = i - 1;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] > s[j]) {
                swap(s[i], s[j]);
                break;
            }
        }
        
        reverse(s.begin() + j + 1, s.end());
        return s;
    }
public:
    string getPermutation(int n, int k) {
        string s;
        for(char c = '1'; c < (n + '1'); c++) {
            s += c;
        }
        
        for(int i = 1; i < k; i++) {
            s = nextPermutation(s);
        }
        return s;
    }
};
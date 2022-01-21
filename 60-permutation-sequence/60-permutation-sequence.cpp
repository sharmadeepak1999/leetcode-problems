class Solution {
public:
    string helper(string n, int k, int i) {
        if(i > k) return n;
        int j = n.length() - 1;
        while(j >= 1 && n[j] <= n[j - 1]) j--;
        if(j == 0) return n;
        
        int m = n.length() - 1;
        while(m >= j - 1 && n[m] < n[j - 1]) m--;
        swap(n[m], n[j - 1]);
        reverse(n.begin() + j, n.end());
        return helper(n, k, ++i);
    }
    
    string getPermutation(int n, int k) {
        string num;
        for(int i = 1; i <= n; i++) {
            num.push_back('0' + i);
        }
        return helper(num, k, 2);
    }
};
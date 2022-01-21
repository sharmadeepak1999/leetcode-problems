class Solution {
public:
    bool nextPermutation(string& num) {
        int i = num.length() - 1;
        while(i > 0 && num[i] <= num[i - 1]) i--;
        if(i == 0) return false;
        
        for(int j = num.length() - 1; j >= i - 1; j--) {
            if(num[j] > num[i - 1]) {
                swap(num[j], num[i - 1]);
                break;
            }
        }
        reverse(num.begin() + i, num.end());
        return true;
    }
    int nextGreaterElement(int n) {
        if(n < 12) return -1;
        string num = to_string(n);
        if(!nextPermutation(num)) return -1;
        long long int res = stoll(num);
        return res > INT_MAX ? -1 : res;   
    }
};
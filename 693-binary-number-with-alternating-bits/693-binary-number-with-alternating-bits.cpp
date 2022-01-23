class Solution {
public:
    bool hasAlternatingBits(int n) {
        // int prev = n & 1;
        // n >>= 1;
        // while(n) {
        //     if(prev == (n & 1)) return false;
        //     prev = n & 1;
        //     n >>= 1;
        // }
        // return true;
        return !((n ^= n / 4) & (n - 1));
    }
};
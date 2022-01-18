class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n > 0) {
            int r = n % 4;
            if(r != 0) break;
            n /= 4;
        }
        return n == 1;
    }
};
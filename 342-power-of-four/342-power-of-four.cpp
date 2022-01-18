class Solution {
public:
    bool isPowerOfFour(int n) {
        // while(n > 0) {
        //     int r = n % 4;
        //     if(r != 0) break;
        //     n /= 4;
        // }
        // return n == 1;
        
        if(n < 0) return false;
        int numberOfOne = 0, bitPosition = 1;
        int currPos = 1;
        while(n) {
            if(n & 1) {
                numberOfOne++;
                bitPosition = currPos; 
            }
            currPos++;
            n >>= 1;
        }
        if(numberOfOne == 1 && (bitPosition & 1)) return true;
        return false;
    }
};
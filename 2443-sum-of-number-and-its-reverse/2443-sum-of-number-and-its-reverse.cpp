class Solution {
public:
    int reverseDigits(int n) {
        int rev = 0;
        while(n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++) {
            if(i + reverseDigits(i) == num) return true;
        }
        return false;
    }
};
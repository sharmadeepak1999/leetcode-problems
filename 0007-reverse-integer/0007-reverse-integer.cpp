class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0) {
            int d = x % 10;
            int cmax = INT_MAX / 10;
            int cmin = INT_MIN / 10;
            if(rev > cmax || (rev == cmax && d > 7)) return 0;
            if(rev < cmin || (rev == cmin && d < -8)) return 0;

            rev = rev * 10 + d;
            x /= 10;
        }
        return rev;
    }
};
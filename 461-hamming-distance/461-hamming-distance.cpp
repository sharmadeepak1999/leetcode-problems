class Solution {
public:
    int hammingDistance(int x, int y) {
        // int hd = 0;
        // while(x > 0 || y > 0) {
        //     if((x & 1) != (y & 1)) hd++;
        //     x >>= 1;
        //     y >>= 1;
        // }
        // return hd;
        int hd = 0;
        int n = x ^ y;
        while(n) {
            n &= (n - 1);
            hd++;
        }
        return hd;
    }
};
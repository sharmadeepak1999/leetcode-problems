class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        for(int i = 0; i <= 31; i++) {
            if(n & 1) c++;
            n = n >> 1;
        }
        return c;
    }
};
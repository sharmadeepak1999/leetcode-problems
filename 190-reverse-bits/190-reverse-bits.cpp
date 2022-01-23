class Solution {
public:
    
uint32_t reverseBits(uint32_t n) {
    uint32_t temp = n;
    for(int j = 0; j < 32; j++) {
        if(temp & 1) {
            n |= (1 << (31 - j));
        } else {
            n &= ~(1 << (31 - j));
        }
        temp >>= 1;
    }
    return n;
}

};
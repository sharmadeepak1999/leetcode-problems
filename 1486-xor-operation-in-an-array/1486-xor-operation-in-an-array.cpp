class Solution {
public:
    int xorOperation(int n, int start) {
        int i = 0, XOR = 0;
        while(i < n) {
            XOR ^= start + 2 * i;
            i++;
        }
        return XOR;
    }
};
class Solution {
public:
    int xorOperation(int n, int start) {
       int nums[n];
        int i = 0, XOR = 0;
        nums[i++] = start + 2 * i;
        while(i < n) {
            nums[i] = start + 2 * i;
            XOR ^= nums[i - 1];
            i++;
        }
        XOR ^= nums[i - 1];
        return XOR;
    }
};
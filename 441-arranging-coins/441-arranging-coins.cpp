class Solution {
public:
    int arrangeCoins(int n) {
        int k = 1;
        while(k <= n) {
            n -= k++;
        }
        return k - 1 ? k - 1 : 1;
    }
};
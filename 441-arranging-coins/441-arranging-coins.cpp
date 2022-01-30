class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0, high = n, ans = 0;
        while(low <= high) {
            long mid = low + (high - low) / 2;
            long res = (mid * (mid + 1)) / 2;
            if(res == n) {
                return mid;
            } else if(res < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};
#define ll long long

class Solution {
public:
    int mySqrt(int x) {
        ll low = 1, high = x, ans = 0;
        while(low <= high) {
            ll mid = (low + high) / 2;
            ll mSq = mid * mid;
            
            if(mSq == x) {
                return mid;
            } else if(mSq > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};
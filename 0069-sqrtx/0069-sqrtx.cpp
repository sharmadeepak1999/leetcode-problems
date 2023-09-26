class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, h = INT_MAX;
        while(l <= h) {
            long long mid = (l + h) / 2;
            
            if(mid * mid == x) {
                return mid;
            } else if(mid * mid < x) {
                l = mid + 1;
            } else h = mid - 1;
        }
        return h;
    }
};
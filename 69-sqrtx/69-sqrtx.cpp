class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        int lo = 1, hi = x / 2;
        
        int ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            long num = (long) mid * mid;
            
            if(num <= x) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;                
            }
        }
        return ans;
    }
};
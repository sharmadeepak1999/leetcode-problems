class Solution {
public:
    double myPow(double x, int n) {
        if(n == INT_MAX) return x == 1 ? 1 : (x == -1) ? -1 : 0;
        if(n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        double ans = 1;
        
        int nn = n;
        
        if(nn < 0) nn = -1 * nn;
        
        while(nn > 0) {
            if(nn % 2 == 1) {
                ans *= x;
                nn--;
            } else {
                x *= x;
                nn /= 2;
            }
        }
        if(n < 0) ans = 1.0 / ans;
        return ans;
    }
};
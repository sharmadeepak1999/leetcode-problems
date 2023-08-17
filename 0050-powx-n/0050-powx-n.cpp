class Solution {
public:
    double myPow(double x, int n) {
        if(n == INT_MIN) {
            if(x == 1) return 1;
            if(x == -1) return 1;
        }
        double ans = 1;
        long long nn = abs(n);
        while(nn > 0) {
            if(nn % 2 == 0) {
                x = x * x;
                nn /= 2;
            } else {
                ans *= x;
                nn--;
            }
        }
        if(n < 0) ans = 1.0 / ans;
        
        return ans;
    }
};
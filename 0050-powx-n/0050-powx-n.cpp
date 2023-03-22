class Solution {
public:
    double helper(double x, int n) {
        if(n == 0) return 1;
        return x * helper(x, --n);
    }
    double myPow(double x, int n) {
        if(n == INT_MAX) return x == 1 ? 1 : (x == -1) ? -1 : 0;
        if(n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        if(n < 0) return (1.0 / helper(x, abs(n)));
        return helper(x, n);
    }
};
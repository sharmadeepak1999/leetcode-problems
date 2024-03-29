class Solution {
public:
    bool isPowerOfThree(int n) {
        /*
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n % 3 != 0) return false;
        return isPowerOfThree(n / 3);
    */
        
        /*
        if(n <= 0) return false;
        double a = (double) log10(n) / log10(3);
        return floor(a) == ceil(a);
        
        */
        
        int power = pow(3, (int) (log(INT_MAX) / log(3)));
        return n > 0 && power % n == 0;
}
    
};
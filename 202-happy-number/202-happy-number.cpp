class Solution {
public:
    
    bool isHappy(int n) {
        set<int> s;
        while(n != 1) {
            int temp = n;
            n = 0;
            while(temp > 0) {
                int d = temp % 10;
                n += d * d;
                temp /= 10;
            }
            if(s.find(n) != s.end()) break;
            s.insert(n);
        }   
        return n == 1;
    }
};
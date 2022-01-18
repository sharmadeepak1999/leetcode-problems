class Solution {
public:
    int nextNum(int n) {
        int temp = n;
        n = 0;
        while(temp > 0) {
            int d = temp % 10;
            n += d * d;
            temp /= 10;
        }
        return n;
    }
    bool isHappy(int n) {
        int slow = n, fast = nextNum(n);
        while(fast != 1 && slow != fast) {
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));
        }   
        return fast == 1;
    }
};
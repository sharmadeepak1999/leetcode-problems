class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int num = x;
        
        long rev_num = 0;
        
        while(num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num /= 10;
        }
        return rev_num == x;
    }
};
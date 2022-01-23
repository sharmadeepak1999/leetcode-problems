class Solution {
public:
    int findComplement(int num) {
        int temp = num, i = 0;
        while(temp) {
            num = num ^ (1 << i);
            i++;
            temp >>= 1;
        }
        return num;
    }
};
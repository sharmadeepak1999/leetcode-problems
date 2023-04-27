class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        int i = 1;
        int currRange = 3;
        int total = 3;
        while(total < n) {
            currRange = currRange + 2;
            total += currRange;
            
            i++;
        }
        
        return i;
    }
};
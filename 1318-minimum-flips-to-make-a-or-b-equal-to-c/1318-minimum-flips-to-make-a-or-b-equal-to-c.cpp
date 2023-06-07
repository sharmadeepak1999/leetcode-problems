class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i = 0; i < 32; i++) {
            int bita = a & (1 << i);
            int bitb = b & (1 << i);
            int bitc = c & (1 << i);
            
            if(bitc == 0) {
                if(bita) flips++;
                if(bitb) flips++;
            } else {
                if(!bita && !bitb) flips++;
            }
        }
        return flips;
    }
};
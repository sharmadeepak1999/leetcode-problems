class Solution {
public:
    int numberOfSteps(int num) {
        if(num <= 0) return 0;
        int steps = 0;
        while(num > 0) {
            steps += num & 1 ? 2 : 1;
            num >>= 1;
        }
        // -1 because when num = 1, it will add +2 to steps
        return steps - 1;
    }
};
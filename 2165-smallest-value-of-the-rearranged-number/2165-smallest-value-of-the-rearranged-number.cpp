class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) return 0;
        vector<int> carr(10, 0);
        
        long long temp = abs(num);
        
        while(temp) {
            int d = temp % 10;
            carr[d]++;
            temp = temp / 10;
        }
        
        long long ans = 0;
        if(num < 0) {
            for(int i = 9; i >= 0; i--) {
                for(int j = 1; j <= carr[i]; j++) {
                    ans = ans * 10 + i;
                }
            }
            
            return -ans;
        } else {
            int countZeros = carr[0];
            
            int i = 1;
            while(carr[i] == 0) i++;
            carr[i]--;
            
            ans = ans * 10 + i;
            
            while(countZeros--) {
                ans = ans * 10;
            }
            
            for(int i = 1; i <= 9; i++) {
                for(int j = 1; j <= carr[i]; j++) {
                    ans = ans * 10 + i;
                }
            }
            
            return ans;
        }
        return 0;
    }
};
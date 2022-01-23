class Solution {
public:
//     int helper(int num) {
//         int count = 0;
//         while(num > 0) {
//             num &= (num - 1);
//             count++;
//         }
//         return count;
//     }
    
//     vector<int> countBits(int n) {
//         vector<int> ans(n + 1, 0);
//         for(int i = 0; i <= n; i++) {
//             ans[i] = helper(i);
//         }
//         return ans;
//     }
    
    
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        int offSet = 0;
        for(int i = 1; i <= n; i++) {
            if(i > 0 && ((i & (i - 1)) == 0)) {
                offSet = i;
                ans[i] = 1;
            } else {
                ans[i] = 1 + ans[i - offSet];            
            }
        }
        return ans;
    }
};
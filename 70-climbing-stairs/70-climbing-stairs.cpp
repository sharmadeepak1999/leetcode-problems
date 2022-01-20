class Solution {
public:
//     int helper(int n, vector<int> &dp) {
//         if(n < 0) return 0;
//         if(n == 1 || n == 0) {
//             return 1;
//         }
//         if(dp[n] != 0) return dp[n];
//         return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n + 1, 0);
        
//         return helper(n, dp);
//     }
    
    int climbStairs(int n) {
        // Starting from end
        int one = 1, two = 1;
        for(int i = 0; i < n - 1; i++) {
            int temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};
class Solution {
public:
    int helper(int num) {
        int count = 0;
        while(num > 0) {
            num &= (num - 1);
            count++;
        }
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            ans[i] = helper(i);
        }
        return ans;
    }
};
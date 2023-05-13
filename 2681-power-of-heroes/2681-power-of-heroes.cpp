class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        long long ans = 0;
        long long s = 0;
        for(auto &num:nums) {
            ans = (ans + (s + num) * num % mod * num % mod) % mod;
            s = (s * 2 + num) % mod;
        }
        return ans;
    }
};
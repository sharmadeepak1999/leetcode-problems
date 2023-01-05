class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0;
        int maxc = 0;
        for(auto &n:nums) {
            if(n == 0) c = 0;
            else maxc = max(maxc, ++c);
        }
        return maxc;
    }
};
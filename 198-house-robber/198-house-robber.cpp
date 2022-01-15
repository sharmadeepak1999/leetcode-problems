class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for(auto n : nums){
            int t = max(n + rob1, rob2);
            rob1 = rob2;
            rob2 = t;
        }
        return rob2;
    }
};
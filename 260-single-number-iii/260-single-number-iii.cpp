class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        long long int XOR = 0;
        for(auto num : nums) XOR ^= num;
        XOR &= -XOR;
        vector<int> res{0, 0};
        for(auto num : nums) {
            res[!((num & XOR) == 0)] ^= num; 
        }
        return res;
    }
};
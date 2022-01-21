class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        long long int XOR = 0;
        for(int i = 0; i < size; i++) {
            XOR ^= nums[i];
        }
        XOR &= -XOR;
        int res1, res2;
        res1 = res2 = 0;
        for(int i = 0; i < size; i++) {
            if((nums[i] & XOR) == 0) {
                res2 ^= nums[i];
            } else {
                res1 ^= nums[i];
            }
        }
        return {res1, res2};
    }
};
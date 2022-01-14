class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto n : nums) {
            ++count[n == 0 ? 0 : n == 1 ? 1 : 2];
        }
        int i = 0;
        for(int j = 1; j <= count[0]; j++) {
            nums[i++] = 0;
        }
        for(int j = 1; j <= count[1]; j++) {
            nums[i++] = 1;
        }
        for(int j = 1; j <= count[2]; j++) {
            nums[i++] = 2;
        }
    }
};
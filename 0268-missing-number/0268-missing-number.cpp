class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int original = (n * (n + 1)) / 2;
        int given = accumulate(nums.begin(), nums.end(), 0);
        
        return original - given;
    }
};
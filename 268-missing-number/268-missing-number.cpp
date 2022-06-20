class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        // Calculate the the required sum that would we from 0 to n, and then get the given sum from all the elements from the nums array. the difference would be the missing number.
        
        int n = nums.size();
        int sum = (n * (n + 1)) / 2;
        
        int givenSum = accumulate(nums.begin(), nums.end(), 0);
        return sum - givenSum;
        */
        
        int res = nums.size();
        
        for(int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};
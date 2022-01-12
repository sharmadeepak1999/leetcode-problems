class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
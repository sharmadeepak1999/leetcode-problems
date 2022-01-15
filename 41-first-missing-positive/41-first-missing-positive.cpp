class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        
        for(auto &n : nums) {
            n = (n <= 0 || n > size) ? size + 1 : n;
        }
        for(int i = 0; i < size; i++) {
            int curr = abs(nums[i]);
            if(curr <= size && nums[curr - 1] > 0) {
                nums[curr - 1] *= -1;
            } 
        }
        
        for(int i = 0; i < size; i++) {
            if(nums[i] > 0) {
                return i + 1;
            }
        }
        return size + 1;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        i = j = 0;
        
        int prevNum = INT_MIN;
        
        while(i < nums.size()) {
            if(nums[i] != prevNum) {
                nums[j] = nums[i];
                prevNum = nums[i];
                j++;
            }    
            i++;
        }
        return j;
    }
};
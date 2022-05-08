class Solution {
public:
    void sortColors(vector<int>& nums) {
      /* 
      1. sort the array, but it is not allowed in this question.
      2. count the no of 1, 2, 0 and then insert them according to the order in a new array, but not allowed in this case.
      3. 
      
      */
        
        
        int i = 0, j = nums.size() - 1;
        int c = 0;
        while(c <= j) {
            if(nums[c] == 0) {
                swap(nums[c], nums[i++]);
            } else if(nums[c] == 2) {
                swap(nums[c], nums[j--]);
                c--;
            }
            c++;
        }
    }
};
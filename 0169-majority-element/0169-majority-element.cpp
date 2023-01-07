class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c = 1;
        int me = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] == me) c++;
            else c--;
            if(c < 0) {
                me = nums[i];
                c = 1;
            }
        }
        return me;
    }
};
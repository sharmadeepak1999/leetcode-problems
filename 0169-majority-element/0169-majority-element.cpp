class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(ele == nums[i]) count++;
            else count--;
            if(count == 0) ele = nums[i], count = 1;
        }
        return ele;
    }
};
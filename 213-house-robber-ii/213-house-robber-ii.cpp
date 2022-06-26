class Solution {
public:
    int helper(vector<int>& nums) {
        int prev = nums[0], prevprev = 0;
        
        int maxMoney = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int pick = nums[i];
            if(i > 1) pick = nums[i] + prevprev;
            int notpick = prev;
            int curr = max(pick, notpick);
            prevprev = prev;
            prev = curr;
            maxMoney = max(maxMoney, curr);
        }
        return maxMoney;
    }
    int rob(vector<int>& nums) {
        // The intitution is that the first and the last element cannot be ever in the same sequence of looting as they are adjacent, so we can first take the first element and ignore the last element, and compute the max loot, and second we should remove the first element, and compute the max loot, the max of theses two loots would be the answer.
        
        if(nums.size() == 1) return nums[0];
        vector<int> temp1, temp2;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0) temp2.push_back(nums[i]);
            if(i != nums.size() - 1) temp1.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};
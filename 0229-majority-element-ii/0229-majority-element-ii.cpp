class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int e1 = INT_MIN, e2 = INT_MIN;
        for(auto &num:nums) {
            if(e1 == num) count1++;
            else if(e2 == num) count2++;
            else if(count1 == 0){
                e1 = num;
                count1++;
            } else if(count2 == 0) {
                e2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        int n = nums.size();
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < n; i++) {
            if(e1 == nums[i]) count1++;
            else if(e2 == nums[i]) count2++;
        }
        vector<int> ans;
        if(count1 > n / 3) ans.push_back(e1);
        if(count2 > n / 3) ans.push_back(e2);

        return ans;
    }
};
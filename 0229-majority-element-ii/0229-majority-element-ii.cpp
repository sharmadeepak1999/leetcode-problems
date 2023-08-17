class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1 = INT_MIN, e2 = INT_MIN, count1 = 0, count2 = 0;
        
        for(auto &num:nums) {
            if(e1 == num) count1++;
            else if(e2 == num) count2++;
            else if(count1 == 0) {
                e1 = num;
                count1 = 1;
            } else if(count2 == 0) {
                e2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        for(auto &num:nums) {
            if(e1 == num) count1++;
            else if(e2 == num) count2++;
        }
        vector<int> ans;
        int n = nums.size();
        if(count1 > n / 3) ans.push_back(e1);
        if(count2 > n / 3) ans.push_back(e2);
        return ans;
    }
};
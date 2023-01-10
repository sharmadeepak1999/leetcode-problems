class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1 = INT_MIN, maj2 = INT_MIN, c1 = 0, c2 = 0;
        int n = nums.size();
        for(auto &el:nums) {
            if(el == maj1) c1++;
            else if(el == maj2) c2++;
            else if(c1 == 0) {
                maj1 = el;
                c1 = 1;
            } else if(c2 == 0) {
                maj2 = el;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }
        
        c1 = 0, c2 = 0;
        for(auto &el:nums) {
            if(el == maj1) c1++;
            else if(el == maj2) c2++;
        }
        vector<int> ans;
        
        if(c1 > (n / 3)) ans.push_back(maj1);
        if(c2 > (n / 3)) ans.push_back(maj2);
        return ans;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1 = INT_MIN, m2 = INT_MIN, c1 = 0, c2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(m1 == nums[i]) {
                c1++;
            } else if(m2 == nums[i]) {
                c2++;
            } else if(c1 == 0) {
                m1 = nums[i];
                c1 = 1;
            } else if(c2 == 0) {
                m2 = nums[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }
        
        vector<int> ans;
        
        c1 = 0, c2 = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == m1) c1++;
            if(nums[i] == m2) c2++;
        }
        
        if(c1 > n / 3) ans.push_back(m1);
        if(c2 > n / 3) ans.push_back(m2);
        
        return ans;
    }
};
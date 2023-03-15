class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            
            while(i != j) {
                if(nums[j] > nums[i]) {
                    ans.push_back(nums[j]);
                    break;
                }
                j = (j + 1) % n;
            }
            if(i == j) ans.push_back(-1);
        }
        return ans;
    }
};
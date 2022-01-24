class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int powerSet = pow(2, nums.size());
        vector<vector<int>> ans;
        for(int i = 0; i < powerSet; i++) {
            int j = 0, temp = i;
            vector<int> res;
            while(temp) {
                if(temp & 1) {
                    res.push_back(nums[j]);
                }
                temp >>= 1;
                j++;
            }
            ans.push_back(res); 
        }
        return ans;
    }
};
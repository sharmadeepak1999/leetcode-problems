class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int desiredSum = (n * (n + 1)) / 2;
        int sum = 0;
        set<int> s;
        vector<int> ans(2);
        for(int i = 0; i < n; i++) {
            if(s.count(nums[i]) > 0) {
                ans[0] = nums[i];
            } else {
                s.insert(nums[i]);
                sum += nums[i];
            }
        }
        ans[1] = desiredSum - sum;
        return ans;
    }
};
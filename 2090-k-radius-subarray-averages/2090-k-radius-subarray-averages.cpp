class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        long long sum = 0;
        int count = 2 * k + 1;
        if(n < count) return ans;
        for(int i = 0; i <= 2 * k; i++) sum += nums[i];
        ans[k] = sum / count;
        int i = 0, j = count, p = k + 1;
        
        while(j < n) {
            sum = sum - nums[i] + nums[j];
            ans[p] = sum / count;
            p++;
            i++;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size = 2 * n;
        vector<int> ans(size);
        int p = 0, q = n;
        for(int i = 0; i < size; i += 2) {
            ans[i] = nums[p];
            ans[i + 1] = nums[q];
            p++;
            q++;
        }
        return ans;
    }
};
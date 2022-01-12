class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size = 2 * n;
        vector<int> ans(size);
        int p = 0, q = n;
        for(int i = 0; i < size; i++) {
            if(i % 2 == 0) {
                ans[i] = nums[p];
                p++;
            } else {
                ans[i] = nums[q];
                q++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int l = i + 1;
            int h = n - 1;
            
            while(l < h) {
                int target = nums[i] + nums[l] + nums[h];
                if(target == 0) {
                    ans.push_back({ nums[i], nums[l], nums[h] });
                    int pl = l, ph = h;
                    while(l < h && nums[l + 1] == nums[l]) l++;
                    while(l < h && nums[h - 1] == nums[h]) h--;
                    l++;
                    h--;
                } else if(target < 0) l++;
                else h--;
            }
        }
        return ans;
    }
};
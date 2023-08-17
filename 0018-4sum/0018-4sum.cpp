class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int l = j + 1, h = n - 1;
                while(l < h) {
                    long long sum = (long long) nums[i] + nums[j] + nums[l] + nums[h];
                    
                    if(sum == target) {
                        ans.push_back({ nums[i], nums[j], nums[l], nums[h] });
                        while(l < h && nums[l] == nums[l + 1]) l++;
                        while(l < h && nums[h] == nums[h - 1]) h--;
                        l++;
                        h--;
                    } else if(sum < target) l++;
                    else if(sum > target) h--;
                }
                while(j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int target2 = target - nums[i];
            for(int j = i + 1; j < n; j++) {
                long long target3 = (long long) target2 - (long long) nums[j];
                int front = j + 1;
                int back = n - 1;
                
                while(front < back) {
                    int sum = nums[front] + nums[back];
                    if(sum == target3) {
                        vector<int> r({nums[i], nums[j], nums[front], nums[back]});
                        
                        ans.push_back(r);
                        
                        while(front < back && nums[front] == r[2]) front++;
                        while(front < back && nums[back] == r[3]) back--;
                    } else if(sum < target3) front++;
                    else back--;
                }
                while(j + 1 < n && nums[j] == nums[j + 1]) j++;
            }
            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
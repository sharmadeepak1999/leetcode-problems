class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> ans;
        int prevX;
        for(int i = 0; i < size - 2; i++) {
            int p1 = i + 1, p2 = size - 1, sum;
            
            int x = nums[i];
            if(i != 0 && nums[i - 1] == x) {
                continue;
            }
            
            while(p1 < p2) {    
                int currY = nums[p1], currZ = nums[p2];            
                sum = x + currY + currZ;
                if(sum == 0) {
                    vector<int> trip{x, currY, currZ};
                    ans.push_back(trip);
                    while(p1 < p2 && nums[p1] == nums[p1 + 1]) p1++;
                    while(p1 < p2 && nums[p2 - 1] == nums[p2]) p2--;
                    p1++;
                    p2--;
                } else if(sum > 0) {
                    p2--;
                } else {
                    p1++;
                }
            }
        }
        return ans;
    }
};
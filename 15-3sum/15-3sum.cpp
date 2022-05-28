class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        
            // Generate all possible combination using three nested loops, and but this won't account for duplicates. So not valid for the current question. Or you can store it in set data structure

            vector<vector<int>> res;

            int size = nums.size();
            for(int i = 0; i < size; i++)
                for(int j = i + 1; j < size; j++)
                    for(int k = j + 1; k < size; k++) 
                        if(nums[i] + nums[j] + nums[k] == 0) res.push_back({ nums[i], nums[j], nums[k]});

            return res;
        */
        
        
        // We will fix the first value, and make a hashmap, and a sum that would be negative of current number, in order to get triplet sum as 0. now we will follow the two sum technique and find the triplet, we could use set data structure to avoid duplicate triplets.
        
        
        
        // The best approach would be to use
        
        
        sort(nums.begin(), nums.end());
        int i = 0; 
        vector<vector<int>> res;
        
        while(i < nums.size()) {
            
            if(i > 0 && nums[i] == nums[i - 1])  { i++; continue; }
            int target = 0-nums[i];
            int lo = i + 1; 
            int hi = nums.size() - 1;
            while(lo < hi) {
                int sum = nums[lo] + nums[hi];
                if(sum == target) {
                    vector<int> v = { nums[lo], nums[i], nums[hi]};
                    res.push_back(v);
                    while(lo < hi && nums[lo] == nums[lo + 1]) {
                        lo++;
                    }
                    while(lo < hi && nums[hi] == nums[hi - 1]) {
                        hi--;
                    }
                    lo++;
                    hi--;
                } else if(sum < target) {
                    lo++;
                } else {
                    hi--;
                }
            }
            i++;
        }
        return res;
    }
};
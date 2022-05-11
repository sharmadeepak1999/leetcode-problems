#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
            // check the sum of every pair using two loops
            
            for(int i = 0; i < nums.size(); i++) {
                for(int j = 0; j < nums.size(); j++) {
                    if(i != j && nums[i] + nums[j] == target) {
                        return {i, j};
                    }
                }
            }
            return {-1, -1};
        */
        
        unordered_map<int, int> m; 
        
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(target - nums[i]) != m.end()) {
                return { i, m[target - nums[i]] }; 
            } else {
                m[nums[i]] = i;
            }
        }
        return {-1, -1};
    }

};
class Solution {
public:
    // void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& per, unordered_set<int> &s) {
    //     if(per.size() == nums.size()) {
    //         ans.push_back(per);
    //         return;
    //     }
    //     for(int j = 0; j < nums.size(); j++) {
    //         if(s.find(j) != s.end()) continue;
    //         per.push_back(nums[j]);
    //         s.insert(j);
    //         helper(nums, ans, per, s);
    //         per.pop_back();
    //         s.erase(j);
    //     }
    // }
    
    
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);
            helper(nums, ans, index + 1);
            swap(nums[index], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        /*
        // We can fix a element from the array and call recursion on the same array but this time skipping the selected element, we could use a hashmap to do so, we will store the index of the selected element in a set and will loop through the array and call recursion for each element except all those that are present in the hashmap.
        
        vector<vector<int>> ans;
        vector<int> per;
        unordered_set<int> s;
        helper(nums, ans, per, s);
        return ans;
        */
        
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;
    }
};
class Solution {
public:
    
//     void helper(vector<int>& nums, set<vector<int>>& s, int i, int n) {
//         if(i == n) {
//             if(s.find(nums) == s.end()) {
//                 s.insert(nums);
//             }
//             return;
//         }
        
//         for(int j = i; j < n; j++) {
//             swap(nums[i], nums[j]);
//             helper(nums, s, i + 1, n);
//             swap(nums[i], nums[j]);
//         }
//     }
    
    
    void helper(unordered_map<int, int>& m, vector<int>& per, vector<vector<int>>& ans, int n) {
        if(per.size() == n) {
            ans.push_back(per);
            return;
        }
        
        for(auto &it : m) {
            if(m[it.first] > 0) {
                per.push_back(it.first);
                m[it.first]--;
                helper(m, per, ans, n);
                m[it.first]++;
                per.pop_back();
            }
        }
    }
    
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*
        // We will generate all the permutation using standard algo of swapping every element from the current index, and then calling the recursion for the next index, but while inserting we will check if the current permutatin is already present in the set, if yes then skip, else insert into the set. now after the recursion overs, we will convert the set into a vector, and return.
        set<vector<int>> s;
        helper(nums, s, 0, nums.size());
        vector<vector<int>> v;
        for(auto &it : s) {
            v.push_back(it);
        }
        return v;
        */
        
        vector<vector<int>> ans;
        vector<int> per;
        unordered_map<int, int> m;
        for(auto &it : nums) m[it]++;
        helper(m, per, ans, nums.size());
        
        return ans;
    }
};
class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& sub, int i) {
        ans.push_back(sub);
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j - 1]) continue;
            sub.push_back(nums[j]);
            helper(ans, nums, sub, j + 1);
            sub.pop_back();
        }
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // A brute force approach is to sort the array and use a set to store the subsets, and call recursion on it, and get all the subset by include exclude method, if the current subset is already present in the set then skip it else insert in the set. this would do the time complexity to be 2^n * log n(for inserting into set) and the space complexity would be O(2^n) to store all the subset into set.
        
        // A better approach would be to sort the array, so as to align the duplicates together, now call the recursion, and the current subset to the answer, then start a loop from the current index to the last index, now if the index is the first one, then pick it and call recursion for the next index, if it is not the first one, and the previous element is equal to the current index, then skip this element to avoid duplicate set, also when the recursion pop out the picked element for further calls.
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        helper(ans, nums, sub, 0);
        return ans;
    }
};
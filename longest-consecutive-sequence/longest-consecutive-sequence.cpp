class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Your Code goes here
        if(nums.empty()) {
            return 0;
        }
        if(nums.size() == 1) {
            return 1;
        }
        sort(nums.begin(), nums.end());
        unordered_set<int> numSet;
        int lcs = 1, clcs = 0;
        for(auto num : nums) {
            numSet.insert(num);
        }

        for(auto num : nums) {
            if(numSet.find(num - 1) == numSet.end()) {
                int j = 0;
                while(numSet.find(num + 1 + j) != numSet.end()) {
                    j++;
                }
                if(j > 0) {
                    clcs = j + 1;
                }
                if(clcs > lcs) {
                    lcs = clcs;
                }
            }
        }
        return lcs;
    }
};
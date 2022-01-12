class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        unordered_map<int, int> freq;
        for(auto n : nums) {
            freq[n]++;
        }
        
        unordered_map<int, int>::iterator it = freq.begin();
        while(it != freq.end()) {
            if(it->second >= 2) {
                count += (it->second * (it->second - 1)) / 2;
            }
            it++;
        }
        return count;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missingNum = 1;
        set<int> s;
        for(auto n : nums) {
            if(n > 0) s.insert(n);
        }
        while(1) {
            if(s.find(missingNum) == s.end()) {
                break;
            } else {
                missingNum++;
            }
        }
        return missingNum;
    }
};
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        int key = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
        for(auto i : items) {
            if(i[key] == ruleValue) count++;
        }
        return count;
    }
};
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0, size = items.size();
        for(int i = 0; i < size; i++) {
            if(ruleKey == "type") {
                count += items[i][0] == ruleValue; 
            } else if(ruleKey == "color") {
                count += items[i][1] == ruleValue; 
            } else {
                count += items[i][2] == ruleValue; 
            }
        }
        return count;
    }
};
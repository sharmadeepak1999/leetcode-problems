class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        for(auto &word:words) {
            unordered_map<char, char> mapped;
            unordered_set<char> mappedValues;
            if(word.length() != pattern.length()) continue;
            int length = word.length();
            bool incl = true;
            for(int i = 0; i < length; i++) {
                if(mapped.find(pattern[i]) != mapped.end()) {
                    if(mapped[pattern[i]] != word[i]) {
                        incl = false;
                        break;
                    }
                } else if(mappedValues.find(word[i]) != mappedValues.end()) {
                    incl = false;
                    break;
                } else {
                    mapped[pattern[i]] = word[i];
                    mappedValues.insert(word[i]);
                }
            }
            if(incl) ans.push_back(word);
        }
        return ans;
    }
};
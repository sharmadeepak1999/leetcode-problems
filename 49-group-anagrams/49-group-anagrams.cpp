class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        // We can traverse through the vector, and assume that the first element as an anagram, we create a hasmap of the chars and count of this element, now we run a inner loop from the next element, and another inner loop that checks that the char in the next element is same as the prev anagram, if it has more or less char, then we break, and store it for the next anagram iteration, this we do by keeping a newIndex pointer that initially has 0, and as we get a element that is not anagram, we update the element at newIndex with the current element, and increase newIndex, if the element is an anagram then we push the element to a temp vector, and at the end of loop we add it to our answer. after this all, we erase all the unwanted elements after the newIndex pointer, as only before it we have elements that are not yet grouped. this gives TLE
        vector<vector<string>> ans; 
        
        for(int i = 0; i < strs.size(); i++) {
            int newIndex = 0;
            vector<string> angs;
            unordered_map<char, int> m;
            
            for(int j = 0; j < strs[i].size(); j++) {
                m[strs[i][j]]++;
            }
            angs.push_back(strs[i]);
            
            for(int j = i + 1; j < strs.size(); j++) {
                unordered_map<char, int> mp = m;
                bool anagram = true;
                for(int k = 0; k < strs[j].size(); k++) {
                    if(mp.find(strs[j][k]) == mp.end()) {
                        strs[newIndex++] = strs[j];
                        anagram = false;
                        break;
                    } else {
                        mp[strs[j][k]]--;
                        if(mp[strs[j][k]] == 0) mp.erase(strs[j][k]);
                    }
                }
                if(!mp.empty() && anagram) {
                    strs[newIndex++] = strs[j];
                } else if(anagram) angs.push_back(strs[j]);
            }
            ans.push_back(angs);
            strs.erase(strs.begin() + newIndex, strs.end());
            i = -1;
        }
        return ans;
        */
        
        vector<string> sortedStrs = strs;
        
        unordered_map<string, vector<string>> m;
        for(auto &s : sortedStrs) {
            string os = s;
            sort(s.begin(), s.end());
            m[s].push_back(os);
        }
        
        vector<vector<string>> ans;
        for(auto &e : m) {
            ans.push_back(e.second);
        }
        return ans;
    }
};
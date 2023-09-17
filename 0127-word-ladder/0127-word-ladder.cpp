class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        
        for(auto &word:wordList) st.insert(word);
        
        queue<pair<string, int>> q;
        q.push({ beginWord, 1 });
        
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == endWord) return steps;
            
            for(auto &ch:word) {
                char org = ch;
                for(char c = 'a'; c <= 'z'; c++) {
                    ch = c;
                    if(st.count(word) > 0) {
                        st.erase(word);
                        q.push({ word, steps + 1 });
                    }
                }
                ch = org;
            }
        }
        return 0;
    }
};
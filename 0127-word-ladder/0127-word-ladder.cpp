class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        
        unordered_set<string> list(wordList.begin(), wordList.end());
    
        q.push({beginWord, 1});
        list.erase(beginWord);
        while(!q.empty()) {
            string str = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(str == endWord) {
                return level;
            }
            for(int i = 0; i < str.length(); i++) {
                string temp = str;
                for(int j = 0; j < 26; j++) {
                    temp[i] = 'a' + j;
                    if(list.find(temp) != list.end()) {
                        list.erase(temp);
                        q.push({temp, level + 1});
                    }
                }
            }
        }
        return 0;
    }
};
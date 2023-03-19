class WordDictionary {
    unordered_map<int, vector<string>> dict;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        dict[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto &s:dict[word.size()]) {
            int i = 0;
            while(i < word.size() && (word[i] == s[i] || word[i] == '.')) {
                i++;
            }
            if(i == word.size()) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
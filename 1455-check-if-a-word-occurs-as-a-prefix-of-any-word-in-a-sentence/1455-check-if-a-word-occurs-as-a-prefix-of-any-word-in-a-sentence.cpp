class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordindex = 1;
        int i = 0;
        
        while(i < sentence.size()) {
            int j = 0;
            while(i < sentence.size() && j < searchWord.size() && sentence[i] != ' ' && sentence[i] == searchWord[j]) i++, j++;
            cout << i << ' ' << j << endl;
            if(j < searchWord.size()) while(i < sentence.size() && sentence[i++] != ' ');
            else return wordindex;
            wordindex++;
        }
        return -1;
    }
};
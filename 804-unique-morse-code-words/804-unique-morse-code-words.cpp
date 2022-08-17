class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> st;
        for(auto &w:words) {
            string morse = "";
            
            for(auto &c:w) {
                morse += arr[c - 97];
            }
            st.insert(morse);

        }
        return st.size();
    }
};
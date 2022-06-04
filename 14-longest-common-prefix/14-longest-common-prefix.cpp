class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];
        
        for(int i = 1; i < strs.size(); i++){
            string cp = "";
            for(int j = 0; j < strs[i].length(); j++) {
                if(lcp[j] != strs[i][j]) break;
                cp += lcp[j];
            }
            lcp = cp;
        }
        return lcp;
    }
};
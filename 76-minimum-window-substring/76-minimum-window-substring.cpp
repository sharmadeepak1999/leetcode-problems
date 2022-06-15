class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> pat;
        
        for(auto &c : t) pat[c]++;
        
        unordered_map<char, int> window;
        
        int start = 0;
        
        int count = 0;
        int left = -1, right = -1, minLen = INT_MAX;
        
        for(int i = 0; i < s.length(); i++){
            window[s[i]]++;
            
            if(window[s[i]] <= pat[s[i]]) count++;
            
            while(count == t.length()) {
                if(minLen > (i - start + 1)) {
                    minLen = (i - start + 1);
                    left = start;
                    right = i;
                }
                
                window[s[start]]--;
                
                if(pat.find(s[start]) != pat.end() && window[s[start]] < pat[s[start]]) count--;
                start++;
            }
        }
        if(left == -1) return "";
        return s.substr(left, right - left + 1);
    }
};
class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int i = 0;
        int len = s.length();
        unordered_map<char, int> hash = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        while(i < len - 1) {
            int curr = hash[s[i]], next = hash[s[i + 1]];
            if(curr < next) num -= curr;
            else num += curr;
            i++;
        }
        num += hash[s[i]];
        return num;
    }
};
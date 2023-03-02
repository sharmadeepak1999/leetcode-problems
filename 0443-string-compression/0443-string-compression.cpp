class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 1;
        int k = 0;
        int c = 1;
        while(i < chars.size()) {
            if(chars[i - 1] != chars[i]) {
                chars[k++] = chars[i - 1];
                if(c > 1) {
                    string cnts = "";
                    while(c > 0) {
                        int d = c % 10;
                        cnts += '0' + d;
                        c = c / 10;
                    }
                    reverse(cnts.begin(), cnts.end());
                    
                    for(auto &ch:cnts) chars[k++] = ch;
                }
                c = 1;
            } else c++;
            i++;
        }
        
        chars[k++] = chars[i - 1];
        if(c > 1) {
            string cnts = "";
            while(c > 0) {
                int d = c % 10;
                cnts += '0' + d;
                c = c / 10;
            }
            reverse(cnts.begin(), cnts.end());

            for(auto &ch:cnts) chars[k++] = ch;
        }
        return k;
    }
};
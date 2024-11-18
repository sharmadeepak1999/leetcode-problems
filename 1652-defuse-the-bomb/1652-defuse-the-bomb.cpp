class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> temp(3 * code.size());
        
        for(int i = 1; i <= 3; i++) {
            for(int j = 0; j < code.size(); j++) temp[code.size() * (i - 1) + j] = code[j];
        }
        
        vector<int> ans(code.size(), 0);
        if(k == 0) return ans;
        int s, e;
        if(k < 0) {
            s = code.size() + k;
            e = code.size() - 1;
        }
        if(k > 0) {
            s = code.size() + 1;
            e = code.size() + k;
        }
        int winsum = accumulate(temp.begin() + s, temp.begin() + e + 1, 0);
        
        for(int i = code.size(); i < 2 * code.size(); i++) {
            ans[i - code.size()] = winsum;
            winsum -= temp[s];
            winsum += temp[e + 1];
            s++, e++;
        }
        return ans;
    }
};
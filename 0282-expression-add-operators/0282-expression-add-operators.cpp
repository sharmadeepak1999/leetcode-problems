class Solution {
public:
    int convert(char d) {
        return d - '0';
    }
    void helper(vector<string> &ans, string num, string exp, int target, int i, long res, long prev) {
        if(i == num.size()) {
            if(res == target) ans.push_back(exp);
            return;
        }
        
        string curr = "";
        long currNum = 0;
        for(int j = i; j < num.size(); j++){
            if(j > i && num[i] == '0') break;
            curr += num[j];
            currNum = currNum * 10 + convert(num[j]);
            
            if(i == 0) helper(ans, num, curr, target, j + 1, currNum, currNum);
            else {
                helper(ans, num, exp + '+' + curr, target, j + 1, res + currNum, currNum);
                helper(ans, num, exp + '-' + curr, target, j + 1, res - currNum, -currNum);
                helper(ans, num, exp + '*' + curr, target, j + 1, res - prev + prev * currNum, prev * currNum);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(ans, num, "", target, 0, 0, 0);
        return ans;
    }
};
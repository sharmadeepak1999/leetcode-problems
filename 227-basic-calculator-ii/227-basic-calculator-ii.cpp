class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int currNum = 0;
        char operation = '+';
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
                if(isdigit(c)) currNum = currNum * 10 + (c - '0');
                if(!isdigit(c) && !iswspace(c) || (i == s.length() - 1)){
                    if(operation == '+') nums.push(currNum);
                    else if(operation == '-') nums.push(-currNum);
                    else if(operation == '*') {
                        int num = nums.top();
                        nums.pop();
                        cout << num << '*' << currNum << '=' << num * currNum << endl;
                        nums.push(num * currNum);
                    } else if(operation == '/') {
                        int num = nums.top();
                        nums.pop();
                                cout << num << '/' << currNum << '=' << num / currNum << endl;
                        nums.push(num / currNum);
                    }
                    currNum = 0;
                    operation = c;
                }
        }
        
        int res = 0;
        while(!nums.empty()) {
            cout << '(' << nums.top() << ") " << "+ ";
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};
class Solution {
public:
    int calculate(string s) {
        /*
        // We will create a stack of numbers, and traverse through the string, if the current char is a space, then we skip, if it is a digit, we add it to the current number variable, this is to account for numbers with multiple digits, if it is a operation, then we check if it is + or -, if yes then we just insert them into the stack with the appropraiate sign, if they are * or / then we pop the top of stack, and compute the result with the curr number, and push result in to stack, after this we initialize currnum as 0. for the 1st operand we will keep the operation variable default value as +, after every other encounter of a operator, we will update the operation variable. after the loop, we will pop all items in the stack and add them to a result, and return.
        
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
                        nums.push(num * currNum);
                    } else if(operation == '/') {
                        int num = nums.top();
                        nums.pop();
                        nums.push(num / currNum);
                    }
                    currNum = 0;
                    operation = c;
                }
        }
        
        int res = 0;
        while(!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
        
        */
        
        int lastNum = 0;
        int res = 0; 
        int currNum = 0;
        char operation = '+';
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
                if(isdigit(c)) currNum = currNum * 10 + (c - '0');
                if(!isdigit(c) && !iswspace(c) || (i == s.length() - 1)){
                    if(operation == '+') {
                        res += lastNum;
                        lastNum = currNum;
                    }
                    else if(operation == '-'){
                        res += lastNum;
                        lastNum = -currNum;
                    }
                    else if(operation == '*') {
                        lastNum *= currNum;
                    } else if(operation == '/') {
                        lastNum /= currNum;
                    }
                    currNum = 0;
                    operation = c;
                }
        }
        res += lastNum;
        return res;
    }
};
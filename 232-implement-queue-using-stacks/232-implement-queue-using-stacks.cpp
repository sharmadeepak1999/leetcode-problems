class MyQueue {
public:
    /*
    
    // Insert into one stack during push operation, but while doing pop or peek check if the other stack is empty if yes then put all the elements of first stack into the other stack, and use the other stack for returning the results. this will give amortized complexity.
    
    stack<int> s1, s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.empty()) {
            while(s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
    */
    
    
    // A not so better approach would be to always before push operation, transfer the content of first stack to the other, and then push the element to the first stack then retransfer the content back from the other stack to first stack. this is to maintain the top as the front of the queue. this will make push O1 time c.
    stack<int> s1, s2;
    MyQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
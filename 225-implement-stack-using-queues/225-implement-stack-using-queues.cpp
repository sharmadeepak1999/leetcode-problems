class MyStack {
public:
    /*
    // We can use two queue, when pushing we pop all the element of the first queue to the second queue, and then push the new element into the first queue, and then push all the element from the second queue to the first queue. this will make the push operation always O(n) time complexity. and other operation O1
    queue<int> q1, q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        while(q1.size()) {
            q2.push(q1.front());
            q1.pop();
        }    
        q1.push(x);
        while(q2.size()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
    */
    
    // We can do it using one queue only, when pushing an element to the queue, we push the element and then reverse the whole queue.
    
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        while(size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
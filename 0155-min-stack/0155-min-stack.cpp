class MinStack {
    pair<int, int> st[10000];
    int tp;
public:
    MinStack() {
        tp = -1;
    }
    
    void push(int val) {
        int curr_min = INT_MAX;
        if(tp != -1)
            curr_min = st[tp].second;
        tp++;
        st[tp] = {val, min(val, curr_min)};
    }
    
    void pop() {
        tp--;
    }
    
    int top() {
        return st[tp].first;
    }
    
    int getMin() {
        return st[tp].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
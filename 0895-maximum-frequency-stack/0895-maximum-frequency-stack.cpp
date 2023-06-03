class FreqStack {
    set<vector<int>, greater<vector<int>>> s;
    unordered_map<int, pair<int, stack<int>>> mp;
    int id;
public:
    FreqStack() {
        id = 0;
    }
    
    void push(int val) {
        if(mp.count(val) <= 0) {
            mp[val].first = 1;
            mp[val].second.push(id);
            
            s.insert({ mp[val].first, mp[val].second.top(), val });
        } else {
            s.erase({ mp[val].first, mp[val].second.top(), val });
            mp[val].first++;
            mp[val].second.push(id);
            s.insert({ mp[val].first, mp[val].second.top(), val });
        }
        id++;
    }
    
    int pop() {
        int val = (*s.begin())[2];
        s.erase({ mp[val].first, mp[val].second.top(), val });
        mp[val].first--;
        if(mp[val].first > 0) {
            mp[val].second.pop();
            s.insert({ mp[val].first, mp[val].second.top(), val });
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
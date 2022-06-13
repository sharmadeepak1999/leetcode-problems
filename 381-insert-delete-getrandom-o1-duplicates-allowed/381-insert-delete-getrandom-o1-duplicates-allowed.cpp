class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;
        
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool res = m.find(val) == m.end();
        
        m[val].insert(v.size());
        v.push_back(val);
        return res;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        
        int lastIndx = v.size() - 1;
        int valIndx = *m[val].begin();
        m[val].erase(valIndx);
        v[valIndx] = v[lastIndx];
        m[v[valIndx]].insert(valIndx);
        m[v[valIndx]].erase(lastIndx);
        v.pop_back();

        if(m[val].size() == 0) m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
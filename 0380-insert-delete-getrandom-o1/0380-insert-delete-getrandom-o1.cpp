class RandomizedSet {
    unordered_set<int> st;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) == st.end()) {
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.find(val) == st.end()) return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        auto it = st.begin();
        int randomNum = rand() % st.size();
        while(randomNum--) it++;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
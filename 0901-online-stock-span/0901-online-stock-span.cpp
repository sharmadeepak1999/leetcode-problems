class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        if(st.empty() || st.top().first > price) st.push({ price, 1 });
        else {
            while(!st.empty() && st.top().first <= price) {
                count += st.top().second;
                st.pop();
            }
            st.push({ price, count});
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
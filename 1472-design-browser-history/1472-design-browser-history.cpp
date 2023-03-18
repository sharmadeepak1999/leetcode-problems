class BrowserHistory {
    stack<string> bck, fwd;
    string curr;
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        bck.push(curr);
        curr = url;
        while(!fwd.empty()) fwd.pop(); 
    }
    
    string back(int steps) {
        while(steps > 0 && !bck.empty()) {
            fwd.push(curr);
            curr = bck.top();
            bck.pop();
            steps--;
        }
        return curr;
    }
    
    string forward(int steps) {
        while(steps > 0 && !fwd.empty()) {
            bck.push(curr);
            curr = fwd.top();
            fwd.pop();
            steps--;
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
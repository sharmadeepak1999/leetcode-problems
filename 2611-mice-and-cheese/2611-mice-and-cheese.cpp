class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int> pq;
        
        int points = accumulate(reward2.begin(), reward2.end(), 0);
        
        for(int i = 0; i < reward1.size(); i++) {
            pq.push(-reward2[i] + reward1[i]);
        }
        
        while(k--) {
            cout << pq.top() << endl;
            points += pq.top();
            pq.pop();
        }
        return points;
    }
};
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        
        vector<int> ans(deck.size());
        
        queue<int> q;
        
        for(int i = 0; i < deck.size(); i++) {
            q.push(i);
        }
        
        for(int i = 0; i < deck.size(); i++) {
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};

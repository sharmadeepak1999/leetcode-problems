class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = costs.size();
        int i = 0, j = n - 1;
        
        for(; i <= j && i < candidates; i++) pq.push({ costs[i], i });
        for(; j >= i && n - j - 1 < candidates; j--) pq.push({ costs[j], j });
        // cout << i << ' ' << j << endl;
        long long cost = 0;
        while(k--) {
            int curr = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(idx < i && i <= j) {
                pq.push({ costs[i], i });
                i++;
            }
            if(idx > j && j >= i) {
                pq.push({ costs[j], j });
                j--;
            }
            cost += curr;
        }
        return cost;
    }
};
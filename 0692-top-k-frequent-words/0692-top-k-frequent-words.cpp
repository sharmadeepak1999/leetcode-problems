class Comparator {
    public: 
        bool operator()(pair<int, string> p1, pair<int, string> p2) {
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        
        for(auto &word:words) {
            mp[word]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> pq;
        
        for(auto &it:mp) {
            pq.push({ it.second, it.first });
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> ans(k);
        int m = k - 1;
        while(pq.size() > 0) {
            ans[m--] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};

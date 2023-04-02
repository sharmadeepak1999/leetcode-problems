class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);
        
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++) {
            v.push_back({ spells[i], i });
        }
        
        sort(v.begin(), v.end());
        int j = m - 1;
        for(int i = 0; i < n; i++) {
            int last = j;
            while(j >= 0 && (long long) v[i].first * potions[j] >= success) j--;
            if(i > 0) ans[v[i].second] += ans[v[i - 1].second];
            ans[v[i].second] += last - j;
        }
        return ans;
    }
};
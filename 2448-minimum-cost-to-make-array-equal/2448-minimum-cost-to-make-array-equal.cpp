class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<long long, long long>> v;
        for(int i = 0; i < n; i++) v.push_back({ nums[i], cost[i] });
        sort(v.begin(), v.end());
        
        vector<pair<long long, long long>> prefix(n);
        prefix[0] = { 0, 0 };
        for(int i = 1; i < n; i++) {
            prefix[i].first = prefix[i - 1].first + v[i - 1].first * v[i - 1].second;
            prefix[i].second = (prefix[i - 1].second + v[i - 1].second);
        }
        long long totalNumCost = prefix[n - 1].first + v[n - 1].first * v[n - 1].second;
        long long totalCost = prefix[n - 1].second + v[n - 1].second;
        long long mini = totalNumCost;
        for(int i = 0; i < n; i++) {
            long long curr = (v[i].first * prefix[i].second) - prefix[i].first;
            curr += (totalNumCost - prefix[i].first - v[i].first * v[i].second) - (v[i].first * (totalCost - prefix[i].second - v[i].second));
            mini = min(mini, curr);
        }
        return mini;
    }
};
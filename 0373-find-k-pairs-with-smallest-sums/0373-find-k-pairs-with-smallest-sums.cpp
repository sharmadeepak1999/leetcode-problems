class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto &num:nums1) {
            pq.push({ num + nums2[0], 0 });
            if(pq.size() == k) break;
        }
        
        vector<vector<int>> ans;
        while(k-- && !pq.empty()) {
            int sum = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            ans.push_back({ sum - nums2[idx], nums2[idx] });
            
            if(idx < nums2.size() - 1) {
                pq.push({ sum - nums2[idx] + nums2[idx + 1], idx + 1});
            }
        }
        return ans;
    }
};
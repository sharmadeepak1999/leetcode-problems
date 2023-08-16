class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        
        int i = 0, j = 0;
        int n = nums.size();
        vector<int> ans;
        while(i < n) {
            while(i < n && i - j + 1 <= k) {
                pq.push({ nums[i], i });
                i++;
            }
            while(pq.size() && pq.top().second < j) pq.pop();
            
            ans.push_back(pq.top().first);
            j++;
        }
        return ans;
    }
};
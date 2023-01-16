class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        int i = 0;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        while(i < n - 1) {
            while(i < n - 1 && intervals[i][1] < intervals[i + 1][0]) {
                ans.push_back(intervals[i]);
                i++;
            }
            while(i < n - 1 && intervals[i][1] >= intervals[i + 1][0] && intervals[i + 1][1] >= intervals[i][0]) {
                intervals[i + 1][0] = min(intervals[i + 1][0], intervals[i][0]);
                intervals[i + 1][1] = max(intervals[i + 1][1], intervals[i][1]);
                i++;
            }
        }
        ans.push_back(intervals[n - 1]);
        return ans;
    }
};
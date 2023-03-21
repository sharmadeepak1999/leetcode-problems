class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> last;
        int n = intervals.size();
        last = intervals[0];
        vector<vector<int>> ans;
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= last[1]) {
                if(intervals[i][1] > last[1]) {
                    last[1] = intervals[i][1];
                }
            } else {
                ans.push_back(last);
                last = intervals[i];
            }
        }
        
        if(last.size()) ans.push_back(last);
        return ans;
    }
};
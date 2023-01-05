class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int arrows = 1;
        
        int mine = points[0][1];
        
        int n = points.size();
        for(int i = 1; i < n; i++) {
            cout << points[i][0] << ' ' << mine << endl;
            if(points[i][0] > mine) {
                mine = points[i][1];
                arrows++;
            } else mine = min(mine, points[i][1]);
        }
        return arrows;
    }
};

// 1, 6
// 2, 8
// 7, 12
// 10, 16
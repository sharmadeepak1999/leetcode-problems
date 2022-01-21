class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();
        unordered_map<float, int> slopes;
        int max = 0;
        for(int i = 0; i < size - max- 1; i++) {
            for(int j = i + 1; j < size; j++) {
                float y = (points[j][1] - points[i][1]), x = (points[j][0] - points[i][0]);
                float slope;
                if(x == 0) slope = INT_MAX;
                else {
                    slope = y / x;
                }
                slopes[slope]++;
                if(slopes[slope] > max) max = slopes[slope];
            }
            slopes.erase(slopes.begin(), slopes.end());
        }
        return max + 1;
    }
};
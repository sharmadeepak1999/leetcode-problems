class Solution {
    bool isPossible(vector<int> &dist, int speed, double hour) {
        double time = 0;
        for(auto &d:dist) {
            time = ceil(time);
            time += (double)d / speed;
            if(time > hour) return false;
        }
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, h = 1e7;
        int ans = -1;
        while(l <= h) {
            int mid = (l + h) / 2;
            
            if(isPossible(dist, mid, hour)) {
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
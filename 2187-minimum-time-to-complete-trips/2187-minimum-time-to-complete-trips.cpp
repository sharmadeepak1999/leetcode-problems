class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, h = 1e14;
        while(l < h) {
            long long mid = (l + h) / 2;
            
            long long tt = 0;
            
            for(auto &t:time) {
                tt += (mid / t);
            }
            if(tt >= totalTrips) h = mid;
            else l = mid + 1;
        }
        return l;
    }
};
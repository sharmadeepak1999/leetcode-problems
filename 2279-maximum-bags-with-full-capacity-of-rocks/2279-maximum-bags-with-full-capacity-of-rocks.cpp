class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        /*
        int n = capacity.size();
        for(int i = 0; i < n; i++) {
            capacity[i] = capacity[i] - rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(capacity[i] >= 0) {
                if(capacity[i] > additionalRocks) break;
                c++;
                additionalRocks -= capacity[i];
            }
        }
        return c;
        */
        
        int n = capacity.size();
        for(int i = 0; i < n; i++) {
            capacity[i] = capacity[i] - rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        
        int count = 0;
        for(auto &c:capacity) {
            if(c >= 0) {
                if(c > additionalRocks) break;
                count++;
                additionalRocks -= c;
            }
        }
        return count;
    }
};
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> diff(n);
        for(int i = 0; i < n; i++) {
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(), diff.end());
        
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(diff[i] >= 0) {
                if(diff[i] > additionalRocks) break;
                c++;
                additionalRocks -= diff[i];
            }
        }
        return c;
    }
};
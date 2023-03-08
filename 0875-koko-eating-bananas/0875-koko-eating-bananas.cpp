class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hr) {
        int l = 1, h = 1000000000;
        while(l < h) {
            int mid = (l + h) / 2;
            
            int totalTime = 0;
            
            for(auto &p:piles) {
                totalTime += (p + mid - 1) / mid;
            }
            
            if(totalTime > hr) l = mid + 1;
            else h = mid;
        }
        return l;
    }
};
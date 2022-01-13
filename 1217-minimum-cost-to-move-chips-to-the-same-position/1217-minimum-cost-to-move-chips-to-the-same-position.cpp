class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int count[2] = {};
        for(auto p : position) {
            ++count[p % 2];
        }
        return min(count[0], count[1]);
    }
};
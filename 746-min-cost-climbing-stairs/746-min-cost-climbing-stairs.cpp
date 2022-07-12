class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int next = 0, nextnext = 0; 
        for(int i = n - 1; i >= 0; i--) {
            int temp = cost[i] + min(next, nextnext);
            nextnext = next;
            next = temp;
        }
        return min(next, nextnext);
    }
};
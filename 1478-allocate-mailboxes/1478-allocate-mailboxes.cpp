class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        vector<vector<int>> front(n + 1, vector<int>(k + 1, INT_MAX));
        for(int i = 0; i <= n; i++) {
            front[i][0] = 0;
        }
        
        for(int j = n - 1; j >= 0; j--) {
            vector<vector<int>> temp(n + 1, vector<int>(k + 1, INT_MAX));
            for(int i = n - 1; i >= 0; i--) {
                for(int p = 1; p <= k; p++) {
                    int cost = front[j + 1][p - 1];
                    if(cost != INT_MAX) {
                        for(int t = i; t <= j; t++) {
                            cost += abs(houses[(i + j) / 2] - houses[t]);
                        }
                    }
                    temp[i][p] = min(cost, front[i][p]);
                }
            }
            front = temp;
        }
        return front[0][k];
    }
};
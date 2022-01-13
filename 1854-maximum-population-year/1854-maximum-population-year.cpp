class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxPopulation = 1, year = INT_MAX;
        int size = logs.size();
        for(int i = 0; i < size; i++) {
            int currPopulation = 1;
            for(int j = 0; j < size; j++) {
                if(j == i) {
                    continue;
                }
                if(logs[j][1] > logs[i][0] && logs[j][0] <= logs[i][0]) {
                    currPopulation++;
                }
            }
            if(currPopulation > maxPopulation) {
                maxPopulation = currPopulation;
                year = logs[i][0];
            } else if(currPopulation == maxPopulation) {
                if(logs[i][0] < year) {
                    year = logs[i][0];
                }
            }
        }
        return year;
    }
};
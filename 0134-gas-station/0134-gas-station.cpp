class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
        int n = gas.size();
        
        for(int i = 0; i < n; i++) {
            if(gas[i] < cost[i]) continue;
            int tank = gas[i];
            int j = i;
            while(1) {
                tank = tank - cost[j];
                if(tank < 0) break;
                j = (j + 1) % n;
                if(i == j) return i;
                tank += gas[j];
            }
        }
        return -1;
        */
        
        
        int totalFuel = 0, totalCost = 0, n = gas.size();
        
        for(int i = 0; i < n; i++) {
            totalFuel += gas[i];
            totalCost += cost[i];
        }
        
        if(totalFuel < totalCost) return -1;
        
        int curr_fuel = 0, start = 0;
        
        for(int i = 0; i < n; i++) {
            if(curr_fuel < 0) {
                start = i;
                curr_fuel = 0;
            }
            curr_fuel += gas[i] - cost[i];
        }
        return start;
        
    }
};
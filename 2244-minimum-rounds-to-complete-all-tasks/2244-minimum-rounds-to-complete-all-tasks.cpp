class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        
        for(auto &t:tasks) mp[t]++;
        
        int rounds = 0;
        for(auto &it:mp) {
            while(it.second > 0) {
                if(it.second == 4) {rounds += 2; it.second -= 4;}
                if(it.second == 1) return -1;
                if(it.second == 2) { rounds++; it.second -= 2;}
                if(it.second == 0) break;
                it.second -= 3;
                rounds++;
            }
        }
        return rounds;
    }
}; 
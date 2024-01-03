class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0;
        int total = 0;
        
        for(auto &row:bank) {
            int count = 0;
            for(auto &i:row) {
                count += (i == '1');
            }
            
            total += (last * count);
            if(count != 0) last = count;
        }
        return total;
    }
};
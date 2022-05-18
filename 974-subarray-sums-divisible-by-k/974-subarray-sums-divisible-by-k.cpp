class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    /*
        // Generate all sub contiguous array using three nested loops and check if the sub array sum is divisble by k. 
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            int c = 0;
            for(int j = i; j < nums.size(); j++) {
                int sum = 0; 
                for(int k = i; k < nums.size() - c; k++) {
                    sum += nums[k];
                }
                
                if(sum % k == 0) {
                    count++;
                }
                c++;
            }
        }
        return count;
    */
        
        unordered_map<int, int> m;

        int sum = 0, count = 0;
        m[0]++;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k; 
            
            if(rem < 0) rem += k;
            
            if(m[rem] > 0) {
                count += m[rem];
            }
            m[rem]++;
        }
        return count;
    }
};
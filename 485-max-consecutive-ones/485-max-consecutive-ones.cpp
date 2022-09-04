class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0; 
        int max1 = 0;
        
        for(auto &a:nums) {
            if(a == 1) max1 = max(max1, ++i);
            else i = 0;
        }
        
        return max1;
    }
};
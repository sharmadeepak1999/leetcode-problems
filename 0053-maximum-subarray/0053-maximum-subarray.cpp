class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        int msum = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                
                if(sum > msum) msum = sum;
            }
            
        }
        return msum;
        */
        
        int msum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if(sum > msum) msum = sum;
            if(sum < 0) {
                sum = 0;
            }
        }
        return msum;
    }
};
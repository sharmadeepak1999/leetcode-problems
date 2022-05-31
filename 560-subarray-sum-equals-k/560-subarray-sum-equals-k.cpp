class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        // We will get all the sub arrays using two loops, and check their sum, if it is equal to k, then increment the count.
        
        int count = 0; 
        
        for(int i = 0; i < nums.size(); i++) {
            int sum = nums[i];
            
            if(sum == k) count++;
            
            for(int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        
        return count;
        
        */
        
        
        /*
        
        // We will create a prefix sum array, that stores the sum of current and previous all elements at any index, now we will traverse through the prefix sum array, if we find that the prefix sum in that index is equal to k, then we will increase the count, we will also maintain a unordered map, we will check if the prefix sum - k, is present in the unordered map, or not, this is because suppose the prefix sum at index 1 is 10, and the prefix sum at index 3 is 19, so we can say that the prefix sum increased from 10 to 19, that is by 9, now suppose if it is equal to k = 9, so we can say that the sum of elemets from index 2 to 3 have to be 9, so that is why we will search prefix sum - k, in the map.
        
        
        unordered_map<int, int> m;
        
        vector<int> prefix;
        
        prefix.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix[i - 1]);
        }
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(prefix[i] == k) count++;
            
            if(m.find(prefix[i] - k) != m.end()) {
                count += m[prefix[i] - k];
            }
            m[prefix[i]]++;
        }
        
        return count;    
        
        */
        
        
        unordered_map<int, int> m;
        
        m[0] = 1;
        int count = 0;
        int presum = 0;
        for(auto a : nums) {
            presum += a;
            
            if(m.find(presum - k) != m.end()) count += m[presum - k];
            m[presum]++;
        }
        
        return count;
    }
};
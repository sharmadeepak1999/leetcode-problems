class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Use two loops and check if the curr num is also present in the rest of the array if present, then push into the result vector. otherwise increment to the next element and repeat.
        
        // Use hashmap and push each element into it while incrementing their count in map, while inserting check if the count becomes 2, if yes then push into the result vector.
        
        // Loop through the array, and use the curr element as an index by subtracting it with -1, check if the element at that index is negative or not, if negative add the index + 1 to the res array, and make curr element negative, repeat. 
        
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1; 
            
            if(nums[index] < 0) res.push_back(index + 1);
            
            nums[index] *= -1;
        }
        return res;
    }
};
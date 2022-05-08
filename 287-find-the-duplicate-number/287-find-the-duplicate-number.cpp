class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // Use two nested loop and check if the ith element again in the whole array except the current index, if it exist else where then it is the duplicate number.
        
        // Sort the array, and check if the first index is equal to the second index if they match, then it is the repeated number, else check the next pair.
        
        
        /*
        // Use set and store elements one by one and then check if the to be inserted element already exist in the set? 
        unordered_set<int> s;
        
        for(auto n : nums) {
            if(s.find(n) != s.end()) {
                return n;
            }
            s.insert(n);
        }
        return -1;
        */
        
        
        // Linked list cycle and floyd's cycle detection method. 
        
        int sl = 0, fs = 0;
        
        while(true) {
            sl = nums[sl];
            fs = nums[nums[fs]];
            
            if(sl == fs) {
                break;
            }
        }
        
        int sl2 = 0;
        
        while(sl != sl2) {
            sl = nums[sl];
            sl2 = nums[sl2];
        }
        return sl;
    }
};
class Solution {
public:
    int noofbits(int n) {
        int count = 0;
        while(n) {
            if(n % 2 == 1) count++;
            n = n / 2;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        vector<int> temp = nums;
        
        sort(temp.begin(), temp.end());
        
        int s = 0, i = 1;
        while(i < nums.size()) {
            if(noofbits(nums[s]) != noofbits(nums[i])) {
                sort(nums.begin() + s, nums.begin() + i);
                s = i;
            }
            i++;
        }
        if(s < nums.size()) {
            sort(nums.begin() + s, nums.end());
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != temp[i]) return false;
        }
        return true;
    }
};
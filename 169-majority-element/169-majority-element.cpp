class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         int n = nums.size(), i;
//         for(i = 0; i < n; i++) {
//             int count = 1;
//             for(int j = i + 1; j < n; j++) {
//                 if(nums[j] == nums[i]) count++;
//             }
//             if(count > (n / 2)) break;
//         }
//         return nums[i];
// ==================================================================
        
//         int n = nums.size();
//         unordered_map<int, int> freq;
//         for(int i = 0; i < n; i++) freq[nums[i]]++;
        
//         unordered_map<int, int>::iterator it = freq.begin();
//         while(it != freq.end()) {
//             if(it -> second > (n / 2)) break;
//             it++;
//         }
//         return it -> first;
//         ===========================================================
        int count = 1, me = 0, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[me]) {
                count++;
            } else count--;
            if(!count) {
                count = 1;
                me = i;
            }
        }
        
        count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[me] == nums[i]) count++;
            
            if(count > n / 2) return nums[me];
        }
        return -1;
    }
};
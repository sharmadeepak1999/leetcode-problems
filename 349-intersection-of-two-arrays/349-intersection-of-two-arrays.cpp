class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> hashmap;
//         vector<int> ans;
//         for(auto x : nums1) {
//             if(hashmap.find(x) == hashmap.end()) {
//                 hashmap[x] = 1;
//             }
//         }
        
//         for(auto x : nums2) {
//             if(hashmap.find(x) != hashmap.end()) {
//                 ans.push_back(x);
//                 hashmap.erase(x);
//             }
//         }
//         return ans;
        
        vector<int> ans;
        int size1 = nums1.size(), prev = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < size1; i++) {
            if(i == 0 || nums1[i] != prev) {
                if(binary_search(nums2.begin(), nums2.end(), nums1[i])) {
                    ans.push_back(nums1[i]);
                }   
            }
            prev = nums1[i];
        }
        return ans;
    }
};
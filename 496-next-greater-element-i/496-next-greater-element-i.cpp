class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for(auto &a : nums1) {
            for(int i = 0; i < nums2.size(); i++) {
                if(a == nums2[i]) {
                    int res = -1;
                    for(int j = i + 1; j < nums2.size(); j++) {
                        if(nums2[j] > nums2[i]) {
                            res = nums2[j];
                            break;
                        }
                    }
                    ans.push_back(res);
                    break;
                }
            }
        }
        return ans;
    }
};
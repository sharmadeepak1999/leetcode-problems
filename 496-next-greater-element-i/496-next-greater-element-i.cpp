class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
        // A naive approach is to use three loops, loop through nums1, for every element in it check the match in nums2, when found, start a loop from the next index of the matched index, and check if a greater number exists, if yes then add it to ans array, else add -1. 
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
        */
        
        
        unordered_map<int, int> m;
        stack<int> s;
        s.push(-1);
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(s.top() < nums2[i] && s.top() != -1) {
                s.pop();
            }
            m[nums2[i]] = s.top();
            
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        
        for(auto &a : nums1) {
            ans.push_back(m[a]);
        }
        return ans;
    }
};
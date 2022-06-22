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
        
        // Craete a stack with initial value as -1, start traversing nums2 from the end, in a while loop check if top of stack is less than the current element and top of stack is not -1, then keep popping, otherwise insert into a map, the current element and the top of the stack which will represent the next greater element, and insert the current element into the stack, after that traverse the nums1, for each element find the correspoding next greater from the map, and insert in ans array and return it. here space complexity is O(nums2.size + nums2.size) one for map and other for stack, time complexity is nums2.size * atmost 1 pop of stack everytime
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
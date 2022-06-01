class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // we can use a hashmap and store the frequency of each element, and during storing if the element frequency goes above n/2, then return that element.
        
        unordered_map<int, int> m;
        
        int n = nums.size();
        for(auto a:nums) {
            m[a]++;
            if(m[a] > (n / 2)) return a;
        }
        return -1;
    }
};
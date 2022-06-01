class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // We can sort the array, and then start counting from the start, we increase the counter if the prev element is same as curr element, if not then we reset the counter to 0, and repeat the process, we will keep check of the number that corresponds to the largest count value, and return it.
        
        
        /*
            // we can use a hashmap and store the frequency of each element, and during storing if the element frequency goes above n/2, then return that element.

            unordered_map<int, int> m;

            int n = nums.size();
            for(auto a:nums) {
                m[a]++;
                if(m[a] > (n / 2)) return a;
            }
            return -1;
        */
        
        
        // We will use Boyer–Moore algorithm, in which we will start traversing the array, and set the result as the first element and count as 1. now we will go further, if we see the next element is same as the result, we increment the count, if it is different, then we will decrement the count, we will do this as long as the count is not 0, when it becomes 0, then we will update the result as the current element, and repeat the process, this algo gurantees that if a majority element exists then it will find it.
        
        int res = nums[0], count = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(count == 0) res = nums[i];
            if(nums[i] != res) 
            {
                count--;
            } else count++;
        }
        return res;
    }
};
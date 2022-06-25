class Solution {
public:
    /*
    void helper(string& nums, int i, int n, vector<string>& ans) {
        if(i >= n) {
            ans.push_back(nums);
            return;
        }
        for(int j = i; j < n; j++) {
            swap(nums[j], nums[i]);
            helper(nums, i + 1, n, ans);
            swap(nums[j], nums[i]);
        }
    }
    string getPermutation(int n, int k) {
        // A brute force approach, We will generate all permutation of the given numbers, and store them in a vector, and then sort the vector, and return the element at k - 1 index. this will give time limit exceeded.
        
        string nums;
        for(int i = 0; i < n; i++) {
            nums.push_back('0' + i + 1);
        }
        vector<string> ans;
        
        helper(nums, 0, n, ans);
        sort(ans.begin(), ans.end());
        
        return ans[k-1];
    }
    */
    
    
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        string ans = "";
        for(int i = 1; i < n; i++) {
            nums.push_back(i);
            fact *= i;
        }
        nums.push_back(n);
        
        k = k - 1;
        while(true) {
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + (k / fact));
            if(nums.size() == 0) break;
            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};
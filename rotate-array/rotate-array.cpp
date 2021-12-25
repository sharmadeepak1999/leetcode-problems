class Solution {
public:
    void reverse(vector<int> &nums, int s, int e) {
        while(s < e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 1 || k == 0) {
            return;
        }
        if(k >= size) {
            k %= size;
        }
        reverse(nums, size - k, size - 1);
        reverse(nums, 0, size - k - 1);
        reverse(nums, 0, size - 1);
    }
};
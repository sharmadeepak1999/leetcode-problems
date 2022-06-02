class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int i = low, j = mid + 1;
        
        for(; i <= mid; i++) {
            while(j <= high && nums[i] > ((long) nums[j] * 2)) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        vector<int> temp;
        
        int left = low, right = mid + 1;
        while(left <= mid && right <= high) {
            if(nums[left] > nums[right]) temp.push_back(nums[right++]);
            else temp.push_back(nums[left++]);
        }
        
        while(left <= mid) {
            temp.push_back(nums[left++]);
        }
        
        while(right <= high) {
            temp.push_back(nums[right++]);
        }
        for(int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) return 0;
        int mid = (low + high) / 2;
        int pairs = mergeSort(nums, low, mid);
        pairs += mergeSort(nums, mid + 1, high);
        pairs += merge(nums, low, mid, high);
        return pairs;
    }
    int reversePairs(vector<int>& nums) {
        /*
            // Brute force, using two loops, check every possibility. gives tle.
            int c = 0;
            for(int i = 0; i < nums.size(); i++) {
                for(int j = i + 1; j < nums.size(); j++) {
                    if(nums[i] > 2 * (long) nums[j]){
                        c++;
                    }
                }
            }
            return c;
        */
        
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
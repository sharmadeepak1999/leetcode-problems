class Solution {
    int merge(vector<int> &nums, int l, int h) {
        if(l >= h) return 0;
        
        int mid = (l + h) / 2;
        vector<int> temp(h - l + 1);
        
        int k = 0;
        int i = l, j = mid + 1;
        int count = 0;
        while(j <= h) {
            while(i <= mid && nums[i] <= (long long) nums[j] * 2) i++;
            count += (mid - i + 1);
            j++;
        }
        i = l, j = mid + 1;
        while(i <= mid && j <= h) {
            if(nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= h) temp[k++] = nums[j++];
        
        for(int p = 0; p < (h - l + 1); p++) nums[l + p] = temp[p];
        return count;
    }
    int mergeSort(vector<int> &nums, int l, int h) {
        if(l >= h) return 0;
        
        int mid = (l + h) / 2;
        
        int leftCount = mergeSort(nums, l, mid);
        int rightCount = mergeSort(nums, mid + 1, h);
        
        int mergeCount = merge(nums, l, h);
        return leftCount + rightCount + mergeCount;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
// [1, 3, 9] [1, 2, 3]
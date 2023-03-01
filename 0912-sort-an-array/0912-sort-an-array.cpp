class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int lsize = mid - left + 1;
        int rsize = right - mid;
        
        
        vector<int> leftarr(lsize), rightarr(rsize);
        
        for(int i = 0; i < lsize; i++) {
            leftarr[i] = nums[left + i];
        }
        
        for(int i = 0; i < rsize; i++) {
            rightarr[i] = nums[mid + 1 + i];
        }
        
        int i = 0, j = 0, k = left;
        
        while(i < lsize && j < rsize) {
            if(leftarr[i] < rightarr[j])
                nums[k++] = leftarr[i++];
            else nums[k++] = rightarr[j++];
        }
        while(i < lsize) nums[k++] = leftarr[i++];
        
        while(j < rsize) nums[k++] = rightarr[j++];
    }
    
    void mergeSort(vector<int> &nums, int si, int ei) {
        if(si >= ei) return;
        
        int mid = (si + ei) / 2;
        mergeSort(nums, si, mid);
        mergeSort(nums, mid + 1, ei);
        merge(nums, si, mid, ei);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
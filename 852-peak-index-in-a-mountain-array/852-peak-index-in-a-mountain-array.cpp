class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /*
        int n = arr.size();
        if(n < 3) return -1;
        
        for(int i = 1; i <= n; i++) {
            if(arr[i - 1] > arr[i]) return i - 1;
        }
        return -1;
        */
        
        int n = arr.size();
        if(n < 3) return -1;
        
        int lo = 1, hi = n - 2, mid;
        
        while(lo <= hi) {
            mid = (lo + hi) / 2;
            
            if(arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) {
                return mid;
            } else if(arr[mid - 1] < arr[mid]) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};
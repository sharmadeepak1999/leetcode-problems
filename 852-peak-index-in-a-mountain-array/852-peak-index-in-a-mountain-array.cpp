class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return -1;
        
        for(int i = 1; i <= n; i++) {
            if(arr[i - 1] > arr[i]) return i - 1;
        }
        return -1;
    }
};
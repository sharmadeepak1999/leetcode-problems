class Solution {
public:
    bool isPresent(vector<int>& arr, int num) {
        int low = 0, high = arr.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == num) return true;
            else if(arr[mid] < num) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        while(k) {
            i++;
            if(!isPresent(arr, i)) --k;
        }
        return i;
    }
};
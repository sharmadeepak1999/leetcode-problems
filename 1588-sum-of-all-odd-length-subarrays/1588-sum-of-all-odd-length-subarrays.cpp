class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int curr = 0;
            for(int j = i; j < n; j++) {
                curr += arr[j];
                if((j - i + 1) & 1) {
                    sum += curr;
                }
            }
        }
        return sum;
    }
};
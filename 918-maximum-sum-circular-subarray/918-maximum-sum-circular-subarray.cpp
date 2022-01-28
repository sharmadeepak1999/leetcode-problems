class Solution {
public:
    int normalSubarraySum(vector<int>& arr) {
        int n = arr.size(), maxSum = arr[0], currSum = arr[0];
        for(int i = 1; i < n; i++) {
            currSum = max(currSum + arr[i], arr[i]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& arr) {
        // int globalMax = INT_MIN, n = arr.size();
        // for(int i = 0; i < n; i++) {
        //     int currSum = arr[i], currMax = arr[i];
        //     for(int j = 1; j < n; j++) {
        //         int index = (i + j) % n;
        //         currSum += arr[index];
        //         currMax = max(currMax, currSum);
        //     }
        //     globalMax = max(globalMax, currMax);
        // }
        // return globalMax;
        
        int normalSum = normalSubarraySum(arr);
        
        if(normalSum < 0) {
            return normalSum;
        }
        
        int arrSum = 0, n = arr.size();
        for(int i = 0; i < n; i++) {
            arrSum += arr[i];
            arr[i] *= -1;
        }
        
        int circularSum = arrSum + normalSubarraySum(arr);
        return max(circularSum, normalSum);
    }
};
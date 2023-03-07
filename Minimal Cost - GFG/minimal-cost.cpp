//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<int> &height, vector<int> &dp, int n, int k) {
        if(n == 1) return 0;
        if(dp[n] != INT_MAX) return dp[n];
        int mini = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(n - j - 1 >= 0)
                mini = min(mini, helper(height, dp, n - j, k) + abs(height[n - j - 1] - height[n - 1]));
            else break;
        }
        
        return dp[n] = mini;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n + 1, INT_MAX);
        helper(height, dp, n, k);
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
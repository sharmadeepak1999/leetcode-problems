//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int helper(int *arr, vector<int> &dp, int n, int prev) {
	    if(n <= 0) return 0;
	    if(n == 1) return arr[n - 1];
	    if(dp[n] != 0) return dp[n];
	    int pick = arr[n - 1] + helper(arr, dp, n - 2, n);
	    int notPick = helper(arr, dp, n - 1, prev);
	    return dp[n] = max(notPick, pick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n + 1, 0);
	    return helper(arr, dp, n, n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int helper(int arr[], vector<int> &dp, int n) {
        if(n <= 0) return 0;
        if(dp[n] != 0) return dp[n];
        int pick = arr[n - 1] + helper(arr, dp, n - 2);
        int notpick = helper(arr, dp, n - 1);
        return dp[n] = max(pick, notpick);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n + 1, 0);
        dp[]
        helper(arr, dp, n);
        return dp[n];
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
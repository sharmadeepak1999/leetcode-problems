//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int helper(int w, int wt[], int val[], int n, int i, vector<vector<int>> &dp) {
        if(i == n - 1) {
            if(wt[n - 1] <= w) return val[n - 1];
            return 0;
        }
        if(dp[w][i] != -1) return dp[w][i];
        int notpick = helper(w, wt, val, n, i + 1, dp);
        int pick = 0;
        if(wt[i] <= w) pick = val[i] + helper(w - wt[i], wt, val, n, i + 1, dp);
        return dp[w][i] = max(pick, notpick);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(1001, vector<int>(n, -1));
       return helper(W, wt, val, n, 0, dp);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
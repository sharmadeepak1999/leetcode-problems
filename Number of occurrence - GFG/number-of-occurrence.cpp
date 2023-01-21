//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int lb = 0, ub = n - 1;
	    
	    int si = -1, ei = -1;
	    
	    while(lb <= ub) {
	        int mid = (lb + ub) / 2;
	        
	        if(arr[mid] == x) {
	            si = mid;
	            ub = mid - 1;
	        } else if(arr[mid] > x) ub = mid - 1;
	        else lb = mid + 1;
	    }
	    
	    lb = 0, ub = n - 1;
	    while(lb <= ub) {
	        int mid = (lb + ub) / 2;
	        
	        if(arr[mid] == x) {
	            ei = mid;
	            lb = mid + 1;
	        } else if(arr[mid] > x) ub = mid - 1;
	        else lb = mid + 1;
	    }
	    return si == -1 ? 0 : ei - si + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
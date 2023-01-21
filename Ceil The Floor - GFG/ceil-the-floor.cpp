//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr, arr + n);
    int lb = 0, ub = n - 1;
    
    pair<int, int> ans = {-1, -1};
    
    while(lb <= ub) {
        int mid = (lb + ub) / 2;
        
        if(arr[mid] == x) {
            ans.first = arr[mid];
            break;
        }
        else if(arr[mid] > x) ub = mid - 1;
        else {
            lb = mid + 1;
            ans.first = arr[mid];
        }
    }
    
    lb = 0, ub = n - 1;
    
    while(lb <= ub) {
        int mid = (lb + ub) / 2;
        
        if(arr[mid] == x) {
            ans.second = arr[mid];
            break;
        }
        else if(arr[mid] < x) lb = mid + 1;
        else {
            ub = mid - 1;
            ans.second = arr[mid];
        }
    }
    
    return ans;
}
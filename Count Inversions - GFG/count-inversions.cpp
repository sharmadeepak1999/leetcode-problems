//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], int s, int e) {
        if(s >= e) return 0;
        long long int count = 0;
        int mid = (s + e) / 2;
        int k = s;
        long long left[mid - s + 1], right[e - mid];
        
        for(int i = s; i <= mid; i++) {
            left[i - s] = arr[i];
        }
        
        for(int j = mid + 1; j <= e; j++) {
            right[j - mid - 1] = arr[j];
        }
        int ls = 0, le = mid - s, rs = 0, re = e - mid - 1;
        while(ls <= le && rs <= re) {
            if(left[ls] <= right[rs]) {
                arr[k++] = left[ls++];
            } else {
                count += le - ls + 1;
                arr[k++] = right[rs++];
            }
        }
        while(ls <= le) arr[k++] = left[ls++];
        while(rs <= re) arr[k++] = right[rs++];
        
        return count;
    }
    long long int mergeSort(long long arr[], int n, int s, int e) {
        if(s >= e) return 0;
        int mid = (s + e) / 2;
        long long int left = mergeSort(arr, n, s, mid);
        long long int right = mergeSort(arr, n, mid + 1, e);
        
        long long int inMerge = merge(arr, s, e);
        return left + right + inMerge;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        return mergeSort(arr, n, 0, n - 1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
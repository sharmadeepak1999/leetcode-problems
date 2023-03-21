//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long s, long long mid, long long e) {
        vector<long long> temp(e - s + 1);
        
        long long i = s, j = mid + 1;
        long long l = 0;
        long long int count = 0;
        while(i <= mid && j <= e) {
            if(arr[i] <= arr[j]) {
                temp[l++] = arr[i++];
            } else {
                count += (mid - i + 1);
                temp[l++] = arr[j++];
            }
        }
        
        while(i <= mid) temp[l++] = arr[i++];
        while(j <= e) temp[l++] = arr[j++];
        
        long long k = s;
        l = 0;
        
        while(k <= e) {
            arr[k++] = temp[l++];
        }
        return count;
    }
    long long int mergeSort(long long arr[], long long s, long long e) {
        if(s >= e) return 0;
        
        long long mid = (s + e) / 2;
        long long int count = 0;
        count += mergeSort(arr, s, mid);
        count += mergeSort(arr, mid + 1, e);
        count += merge(arr, s, mid, e);
        
        return count;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        return mergeSort(arr, 0, n - 1);
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
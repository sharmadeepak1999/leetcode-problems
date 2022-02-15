// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
            // code here 
            // int res = 0;
            // for(int i = 0; i < n; i++) {
            //     int sum1 = 0, sum2 = 0;
            //     for(int j = i; j < n; j++) {
            //         sum1 += arr1[j];
            //         sum2 += arr2[j];
            //         if(sum1 == sum2) {
            //             res = max(res, j - i + 1);
            //         }
            //     }
            // }
            
            unordered_map<int, int> m;
            int res = 0, presum = 0;
            for(int i = 0; i < n; i++) {
                presum += arr1[i] == arr2[i] ? 0 : (arr1[i] == 1 ? 1 : -1);
                if(presum == 0) {
                res = i + 1;
            }
            if(m.find(presum) != m.end()) {
                res = max(res, i - m[presum]);
            } else m.insert({ presum, i });
            }
            return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
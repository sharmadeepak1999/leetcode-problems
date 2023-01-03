//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // long long gcd(long long a, long long b) {
    //     long long gmin = min(a, b);
        
    //     while(gmin) {
    //         if(a % gmin == 0 && b % gmin == 0) break;
    //         gmin--;
    //     }
    //     return gmin;
    // }
    
    // long long gcd(long long a, long long b) {
    //     if(a == 0) return b;
    //     if(b == 0) return a;
        
    //     if(a == b) return a;
        
    //     if(a > b) return gcd(a - b, b);
    //     return gcd(a, b - a);
    // }
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    vector<long long> lcmAndGcd(long long a, long long b) {
        // code here
        long long g = gcd(a, b);
        return { (a/g) * b, g};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
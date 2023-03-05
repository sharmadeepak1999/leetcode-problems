//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void helper(int num, string s, char prev) {
        if(num <= 0) {
            cout << s << " ";
            return;
        }
        
        if(prev == '0') {
            helper(num - 1, s + '0', '0');
            helper(num - 1, s + '1', '1');
        }
        else if(prev == '1') helper(num - 1, s + '0', '0');
    }
    void generateBinaryStrings(int& num){
        //Write your code
        int n = num - 1;
        helper(n, "0", '0');
        helper(n, "1", '1');
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
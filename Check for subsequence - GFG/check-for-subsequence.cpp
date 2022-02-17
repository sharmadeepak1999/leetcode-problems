// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends

class Solution{
    public:
    bool helper(string a, string b, int i, int j) {
        if(i < 0) return true;
        if(j < 0) return false;
        
        if(a[i] == b[j]) {
            return helper(a, b, i--, j--);
        } else {
            return helper(a, b, i, j--);
        }
    }
    bool isSubSequence(string a, string b) 
    {
        // code here
        int i = a.length() - 1, j = b.length() - 1;
        while(i >= 0 && j >= 0) {
            if(a[i] == b[j]) {
                i--;
                j--;
            } else j--;
        }
        if(i < 0) return true;
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 
  // } Driver Code Ends
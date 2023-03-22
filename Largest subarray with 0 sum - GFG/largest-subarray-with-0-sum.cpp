//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        // Your code here
        unordered_map<int, int> mp;
        
        vector<int> presum(n, 0);
        int prevSum = nums[0];
        int sum;
        mp[0] = 0;
        int ls = 0;
        for(int i = 1; i < n; i++) {
            sum = prevSum;
            prevSum = sum + nums[i];
            if(mp.find(sum) != mp.end()) ls = max(ls, i - mp[sum]);
            else mp[sum] = i;
        }
        
        if(prevSum == 0) return n;
        
        return ls;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
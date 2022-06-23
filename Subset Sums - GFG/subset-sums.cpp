// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void helper(vector<int>& arr, int n, int i, vector<int>& sub, vector<int>& ans) {
        if(i >= n) {
            ans.push_back(accumulate(sub.begin(), sub.end(), 0));
            return;
        }
        
        sub.push_back(arr[i]);
        helper(arr, n, i + 1, sub, ans);
        sub.pop_back();
        helper(arr, n, i + 1, sub, ans);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans, sub;
        helper(arr, n, 0, sub, ans);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
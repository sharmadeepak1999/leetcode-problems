//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int missingNumber(int a[], int n)
{
    // Your code goes here
    /*
    int asum = (n * (n + 1)) / 2;
    
    int gsum = accumulate(a, a + n - 1, 0);
    
    return asum - gsum;
    */
    
    int sum = 0;
    
    for(int i = 1; i <= n; i++) sum ^= i;
    
    for(int i = 0; i < n - 1; i++) sum ^= a[i];
    return sum;
}
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


bool comp(pair<int, int> a, pair<int, int> b) {
    return ((double) a.second / a.first) > ((double) b.second / b.first);
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++) {
            v.push_back({ arr[i].weight, arr[i].value });
        }
        
        sort(v.begin(), v.end(), comp);
        
        int i = 0;
        double value = 0;
        while(w > 0 && i < n) {
            if(v[i].first <= w) {
                w -= v[i].first;
                value += v[i].second;
            } else {
                value += v[i].second * ((double) w / v[i].first);
                w -= v[i].first;
            }
            i++;
        }
        
        return value;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
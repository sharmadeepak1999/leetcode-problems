//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<int> dp(4, 0);
        dp[0] = max(points[0][1], points[0][2]);
        dp[1] = max(points[0][0], points[0][2]);
        dp[2] = max(points[0][0], points[0][1]);
        dp[3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int i = 1; i < n; i++) {
            vector<int> ndp(4, 0);
            for(int j = 0; j <= 3; j++) {
                int maxi = 0;
                for(int k = 0; k < 3; k++) {
                    if(j == k) continue;
                    maxi = max(maxi, points[i][k] + dp[k]);
                }
                ndp[j] = maxi;
            }
            dp = ndp;
        }
        return dp[3];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
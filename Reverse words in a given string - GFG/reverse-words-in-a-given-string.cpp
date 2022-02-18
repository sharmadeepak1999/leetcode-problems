// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string str) 
    { 
        // code here 
        int s = 0, e = 0;
        for(int i = 0; i < str.length(); i++) {
            char c = str[i];
            if(c == '.') {
                reverse(str.begin() + s, str.begin() + e);
                s = e + 1;
            } else if(i == str.length() - 1) {
                reverse(str.begin() + s, str.end());
            }
            e++;
        }
        reverse(str.begin(), str.end());
        return str;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
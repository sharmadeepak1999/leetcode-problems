//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    char txtMap[26] = {0};
	    char patMap[26] = {0};
	    int k = pat.size();
	    for(int i = 0; i < k; i++) {
	        txtMap[txt[i] - 'a']++;
	        patMap[pat[i] - 'a']++;
	    }
	    
	    int anagrams = 0;
	    
	    bool isPossible = true;
	    for(int i = 0; i < 26; i++) {
	        if(txtMap[i] != patMap[i]) {
	            isPossible = false;
	            break;
	        }
	    }
	    if(isPossible) anagrams++;
	    
	    for(int i = k; i < txt.size(); i++) {
	        txtMap[txt[i - k] - 'a']--;
	        txtMap[txt[i] - 'a']++;
	        
    	    bool isPossible = true;
    	    for(int i = 0; i < 26; i++) {
    	        if(txtMap[i] != patMap[i]) {
    	            isPossible = false;
    	            break;
    	        }
    	    }
    	    if(isPossible) anagrams++;
	    }
	    return anagrams;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
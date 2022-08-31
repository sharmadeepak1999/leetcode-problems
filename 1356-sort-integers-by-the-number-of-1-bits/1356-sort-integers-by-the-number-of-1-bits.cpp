class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> temp(n);
        for(int i = 0; i < n; i++) {
            temp[i] = { __builtin_popcount(arr[i]), arr[i] };
        }
        sort(temp.begin(), temp.end());
        vector<int> ans(n);
        
        int i = 0;
        for(auto &it:temp) ans[i++] = it.second;
        return ans;
    }
};
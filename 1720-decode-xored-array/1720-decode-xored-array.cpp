class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int size = encoded.size() + 1;
        vector<int> ans(size);
        ans[0] = first;
        for(int i = 1; i < size; i++) {
            ans[i] = encoded[i - 1] ^ ans[i - 1];
        }
        return ans;
    }
};
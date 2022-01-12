class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = -1;
        return accumulate(begin(mat), end(mat), 0, [&](int s, vector<int> &v) {
            return s + v[++i] + (i == v.size() - i - 1 ? 0 : v[v.size() -i - 1]);
        });
    }
};
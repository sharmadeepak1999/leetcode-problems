class Solution {
public:

    void helper(int n, int i, int &count, unordered_set<int>& s) {
        if(s.size() == n){
            count++;
            return;
        }
        for(int j = 1; j <= n; j++){
            if(s.find(j) == s.end() && (j % i == 0 || i % j == 0)){
                s.insert(j);
                helper(n, i + 1, count, s);
                s.erase(j);
            }
        }
    }
    int countArrangement(int n) {
        unordered_set<int> s;
        int count = 0;
        helper(n, 1, count, s);
        return count;
    }
};
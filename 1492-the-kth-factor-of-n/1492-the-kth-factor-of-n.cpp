class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> secondFactors;
        int count = 0;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if(i * i != n) secondFactors.push_back(n / i);
                if(++count == k) return i; 
            }
        }
        if(secondFactors.size() + count < k) return -1;
        return secondFactors[secondFactors.size() - (k - count)];
    }
};
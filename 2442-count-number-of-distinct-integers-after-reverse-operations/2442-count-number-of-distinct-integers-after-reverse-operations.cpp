class Solution {
    int reverseDigits(int n) {
        int rev = 0;
        
        while(n > 0) {
            int d = n % 10;
            rev = rev * 10 + d;
            n /= 10;
        }
        return rev;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto &num:nums) {
            s.insert(num);
            s.insert(reverseDigits(num));
        }
        return s.size();
    }
};
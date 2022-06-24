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
        //We can select an element from the range using a for loop and call recursion for the next index if the current element is not present in the set, we will also check the condition of both divisible operation.
        // One another approaxh would be to create new nums array with all the number within the range from 1-n, now call the recursive call with nums and curr index, now for run a loop in the recur func and swap every element with the first element or the current index, and call the recursion on the next index, this is because we want to generate all permutation starting with each number, we will before inserting will also check for the divisibility condition then only call the recursion else not.
        
        unordered_set<int> s;
        int count = 0;
        helper(n, 1, count, s);
        return count;
    }
};
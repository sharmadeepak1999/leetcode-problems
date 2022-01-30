class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0, end = numbers.size() - 1;
        
        while(first < end) {
            int sum = numbers[first] + numbers[end];
            if(sum == target) break;
            else if(sum < target) first++;
            else end--;
        }
        return {first + 1, end + 1};
    }
};
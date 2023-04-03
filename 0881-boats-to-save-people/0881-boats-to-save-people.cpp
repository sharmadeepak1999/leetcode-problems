class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int i = 0, j = people.size() - 1;
        int boat = 0;
        while(i <= j) {
            if(i == j) i++;
            else if(people[i] + people[j] <= limit) i++, j--;
            else j--;
            boat++;
        }
        
        return boat;
    }
};
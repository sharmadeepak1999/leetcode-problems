class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        /*
            // Brute force: Caculate the value for all combination using two loops, and find the maxval among them as long as the given x difference condition is met. this gives tle.

            int maxval = INT_MIN;
            for(int i = 0; i < points.size(); i++) {
                for(int j = i + 1; j < points.size(); j++) {
                    int xdiff = abs(points[i][0] - points[j][0]);
                      if(xdiff <= k) {
                          maxval = max(maxval, points[i][1] + points[j][1] + xdiff);
                      } else break;
                }
            }
            return maxval;
        */
        
        
        // If we clearly see the equation, we can simplify it to (y1 + y2 + (-(x1 - x2))) this is because x1 < x2, for i < j. so when we simplify the abs function we get the above equation. (y1 - x1 + y2 + x2), here 1 is i, and 2 is j. So if we see for any index j, we can say that the y2 + x2 is fixed so to get the maximum value at this j, we need to get the max value of y1 - x1 from all previous points, so inorder to get the max value of all previous points, we can store it in a priority queue, we will store the diff y1 - x1 and the x1, in the priority queue, we store x1 to check for the satisfying condition, |x1 - x2| <= k, we will pop the pq, as long as the condition is not satisfied, and if the pq remain unempty after popping we will take the top of pq, and calculate the equation value with it, and check if it is maximum, we will repeat this process for every element in the array. this approach has a space complexity of O(n) in case when we need to store the whole array into the pq, and inserting into pq has O(log n) time complexity, so in worse situation it will be O(n logn) time complexity.
        
        priority_queue<pair<int, int>> pq;
        
        int maxval = INT_MIN;
        
        for(int i = 0; i < points.size(); i++) {
            while(!pq.empty() && abs(points[i][0] - pq.top().second > k)) pq.pop();
            if(!pq.empty()) {
                maxval = max(maxval, points[i][0] + points[i][1] + pq.top().first);        
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return maxval;
    }
};
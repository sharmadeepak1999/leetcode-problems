class Solution {
public:
    int maxArea(vector<int>& height) {
        // Using two nested loop, go through every combination of area we can generate and get the maximum area.
        
        // We will use two pointer technique, we will calculate the area using left and right pointer, and compare it with the max area, after that we will change the pointer that is smaller, as we can potentially get a larger area, using a bigger vertical line. we will repeat this process. for case when both the pointer have same value we can decide which pointer to change.
        
        int maxarea = INT_MIN;
        int l = 0, r = height.size() - 1;
        
        while(l < r) {
            maxarea = max(maxarea, (r - l) * min(height[r], height[l]));
            if(height[l] <= height[r])
                l++; 
            else r--;
        }
        return maxarea;
    }
};
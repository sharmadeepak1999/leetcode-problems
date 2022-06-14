class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        // The brute force method is to for every element we will find the left smaller and right smaller element, and the difference between their indexes would be the width of the rectangle, and check if the area formed by the element and the width is max, repeat the process.
    
        int maxArea = INT_MIN;
        
        for(int i = 0; i < heights.size(); i++) {
            int rIndex = i, lIndex = i; 
            
            for(int j = i - 1; j >= 0; j--) {
                if(heights[j] < heights[i]) break;
                lIndex = j;
            }
            
            for(int j = i + 1; j < heights.size(); j++) {
                if(heights[j] < heights[i]) break;
                rIndex = j;
            }
            int width = rIndex - lIndex + 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
        */
        
        
        vector<int> lsmall(heights.size());
        
        stack<int> s1;
        
        for(int i = 0; i < heights.size(); i++) {
            while(!s1.empty()) {
                if(heights[s1.top()] < heights[i]) break;
                else s1.pop();
            }
            if(s1.empty()) lsmall[i] = 0;
            else lsmall[i] = s1.top() + 1;
            
            s1.push(i);
        }
        
        vector<int> rsmall(heights.size());
        
        stack<int> s2;
        
        for(int i = heights.size() - 1; i >= 0; i--) {
            while(!s2.empty()) {
                if(heights[s2.top()] < heights[i]) break;
                else s2.pop();
            }
            if(s2.empty()) rsmall[i] = heights.size() - 1;
            else rsmall[i] = s2.top() - 1;
            
            s2.push(i);
        }
        
        int maxArea = INT_MIN;
        for(int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, (rsmall[i] - lsmall[i] + 1) * heights[i]);
        }
        
        return maxArea;
    }
};
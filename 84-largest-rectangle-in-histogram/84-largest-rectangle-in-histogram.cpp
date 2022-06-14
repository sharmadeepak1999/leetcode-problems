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
        
        /*
        // A better approach would be to pre compute the left and right smaller element of each index, we will achieve it by using a stack, and a left and right smaller array, we will loop through each element and check if the top of the stack is less than the current element, then that would be our boundary, if it is bigger than we will pop it out of the stack, we will repeatedly pop out of stack as long as the top element is greater than the current element or the stack is not empty, after that we will check if the stack is empty, that means we couldn't find a smaller element, so we will use the extermee as the boundary, which is 0 for left smaller, and heights.size() - 1 for right smaller, if stack is not empty than the the boundary will be top of the stack we will incremenet or decremenet it depends what we aer finding left or right smaller. after these we will insert the currenet element index into the stack and repeat the process for rest of the element.
        
        
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
        */
        
        stack<int> s;
        int maxArea = 0;
        
        for(int i = 0; i <= heights.size(); i++) {
            while(!s.empty() && (i == heights.size() || heights[s.top()] >= heights[i])) {
                int height = heights[s.top()];
                s.pop();
                
                int width;
                if(s.empty()) width = i;
                else width = i - s.top() - 1;
                
                maxArea = max(maxArea, (width * height));
            }
            s.push(i);
        }
        return maxArea;
    }
};
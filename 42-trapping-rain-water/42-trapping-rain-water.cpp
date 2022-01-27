class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size(), cap = 0;
//         for(int i = 1; i < size - 1; i++) {
//             int lMax = height[i];
//             for(int j = 0; j < i; j++) {
//                 lMax = max(lMax, height[j]);
//             }
            
//             int rMax = height[i];
//             for(int j = i + 1; j < size; j++) {
//                 rMax = max(rMax, height[j]);
//             }
//             cap += min(lMax, rMax) - height[i];
//         }
        
        int lMax[size];
        lMax[0] = height[0];
        for(int i = 1; i < size; i++) {
            lMax[i] = max(height[i], lMax[i - 1]);
        }
        
        int rMax[size];
        rMax[size - 1] = height[size - 1];
        for(int i = size - 2; i >= 0; i--) {
            rMax[i] = max(height[i], rMax[i + 1]);
        }
        
        for(int i = 1; i < size - 1; i++) {
            cap += min(lMax[i], rMax[i]) - height[i];
        }
        return cap;
    }
};
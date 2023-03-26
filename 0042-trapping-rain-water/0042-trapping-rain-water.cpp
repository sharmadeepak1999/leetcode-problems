class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n, 0), suffixMax(n, 0);
        prefixMax[0] = height[0];
        int i = 1;
        while(i < n) {
            prefixMax[i++] = max(prefixMax[i - 1], height[i]);
        }
        suffixMax[n - 1] = height[n - 1];
        i = n - 2;
        
        while(i >= 0) {
            suffixMax[i--] = max(suffixMax[i + 1], height[i]);
        }
        
        int trappedWater = 0;
        for(int i = 1; i < n - 1; i++) {
            trappedWater += (min(prefixMax[i], suffixMax[i]) - height[i]);
        }
        return trappedWater;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n, 0), post(n, 0);
        for(int i = 1; i < n; i++) {
            pre[i] = max(height[i - 1], pre[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--) {
            post[i] = max(height[i + 1], post[i + 1]);
        }
        
        int amount = 0;
        
        for(int i = 0; i < n; i++) {
            int a = min(pre[i], post[i]) - height[i];
            if(a > 0) amount += a;
        }
        return amount;
    }
};
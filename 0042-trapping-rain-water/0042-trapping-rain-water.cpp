class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = 0;
        for(int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], height[i - 1]);
        }
        suf[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], height[i + 1]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int t = min(pre[i], suf[i]) - height[i];
            if(t > 0) ans += t;
        }
        return ans;
    }
};
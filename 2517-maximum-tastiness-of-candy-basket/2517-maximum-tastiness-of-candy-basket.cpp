class Solution {
    bool isPossible(vector<int> &price, int k, int mid) {
        int prev = price[0];
        k--;
        cout << mid << endl;
        for(int i = 1; i < price.size(); i++) {
            if(price[i] - prev >= mid) {
                prev = price[i];
                k--;
                if(k == 0) return true;
            }
        }
        return false;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int l = 0, h = price[n - 1] - price[0];
        while(l <= h) {
            int mid = (l + h) / 2;
            
            if(isPossible(price, k, mid)) l = mid + 1;
            else h = mid - 1;
        }
        return h;
    }
};
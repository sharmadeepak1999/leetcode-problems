class Solution {
    bool isPossible(vector<int> &nums, int p, int mid) {
        int count = 0;
        int prev = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(prev != -1 && abs(nums[i] - prev) <= mid) {
                count++;
                prev = -1;
            } else prev = nums[i];
            if(count == p) return true;
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, h = abs(nums[n - 1] - nums[0]);
        cout << endl;
        while(l <= h) {
            int mid = (l + h) / 2;
            if(isPossible(nums, p, mid)) {
                h = mid - 1;
            } else l = mid + 1;
        }
        return l;
    }
};
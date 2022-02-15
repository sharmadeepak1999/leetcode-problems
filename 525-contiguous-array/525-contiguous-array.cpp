class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        // for(int i = 0; i < size; i++) {
        //     int no = 0, nz = 0;
        //     for(int j = i; j < size; j++) {
        //         nums[j] == 0 ? (nz++) : (no++);
        //         if(nz == no) res = max(res, 2 * nz);
        //     }
        // }
        
        unordered_map<int, int> m;
        int presum = 0;
        for(int i = 0; i < size; i++) {
            presum += (nums[i] == 0) ? -1 : 1;
            if(presum == 0) {
                res = i + 1;
            }
            if(m.find(presum) != m.end()) {
                res = max(res, i - m[presum]);
            } else m.insert({ presum, i });
        }
        return res;
    }
};
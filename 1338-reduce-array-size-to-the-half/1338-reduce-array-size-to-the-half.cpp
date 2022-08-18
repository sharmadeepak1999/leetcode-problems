class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(auto &a:arr) {
            mp[a]++;
        }
        
        vector<int> frequency;
        
        for(auto &m:mp) {
            frequency.push_back(m.second);
        }
        
        int count = 0;
        int n = arr.size();
        
        sort(frequency.begin(), frequency.end(), greater<int>());
        int i = 0;
        for(auto &f:frequency) {
            count += f;
            i++;
            if(count >= n / 2) break;
        }
        
        return i;
    }
};
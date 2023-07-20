class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        stack<int> st;
        
        int i = 0;
        
        while(i < n) {
            if(asteroids[i] > 0) st.push(asteroids[i]);
            else {
                while(st.size() && st.top() < -asteroids[i]) st.pop();
                if(st.size()) {
                    if(st.top() == -asteroids[i]) st.pop();
                } else ans.push_back(asteroids[i]);
            }
            i++;
        }
        vector<int> rem;
        while(st.size()) {
            rem.push_back(st.top());
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        ans.insert(ans.end(), rem.begin(), rem.end());
        return ans;
    }
};
class Solution {
public:
    /*
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // A brute force approach is to loop through all temps, and for each day temp, find in the rest of the array a temp greater than the current temp, push the distance between them into the array.
        int size = temperatures.size();
        vector<int> ans(size, 0);
        
        for(int i = 0; i < size; i++) {
            for(int j = i; j < size; j++) {
                if(temperatures[j] > temperatures[i]) {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
    */
    
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // We will use a monotonic stack, we will iterate through the array, and if we find the top of the stack is less than the curr temp, then we update an answer array of the top of the stack position, and pop, we do this as long as the top of the stack becomes greater than the curr element, at last we push the curr element to the stack.
        int size = temperatures.size();
        vector<int> ans(size, 0);
        stack<int> st;

        st.push(0);
        for(int i = 1; i < size; i++) {
            int curr = temperatures[i];
            while(st.size() && curr > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
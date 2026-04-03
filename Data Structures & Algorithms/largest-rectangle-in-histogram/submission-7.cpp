class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int m = 0;
        for (int i = 0; i < heights.size(); i++) {
            int tmp = i;
            while(!st.empty() and st.top().second > heights[i]) {
                m = max(m, st.top().second*(i-st.top().first));
                tmp = st.top().first;
                st.pop();
            }
            st.push({tmp, heights[i]});
        }
        while(!st.empty()) {
            m = max(m, st.top().second*(static_cast<int>(heights.size()) - st.top().first));
            st.pop();
        }
        return m;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty()) {
                if (s[i] == '}' and st.top() == '{'
                or s[i] == ')' and st.top() == '('
                or s[i] == ']' and st.top() == '[') {
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        }
        return st.empty();
    }
};

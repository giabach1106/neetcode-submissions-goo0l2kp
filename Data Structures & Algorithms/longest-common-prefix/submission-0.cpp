class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int k = 0;
            while (k < strs[i].size() and s[k] == strs[i][k])
                k++;
            s = s.substr(0, k);
        }
        return s;
    }
};
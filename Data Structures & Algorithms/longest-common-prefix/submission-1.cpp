class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (auto str : strs) {
            int i = 0;
            while (i < str.size() and i < res.size() and str[i] == res[i])
                i++;
            res = res.substr(0, i);
        }
        return res;
    }
};
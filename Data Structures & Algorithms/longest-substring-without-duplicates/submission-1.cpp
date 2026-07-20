class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> se;
        int l = 0, r = 0;
        while (r < s.size()) {
            while (se.count(s[r])) {
                se.erase(s[l]);
                l++;
            }
            se.insert(s[r]);
            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};

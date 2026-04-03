 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = 0;
        unordered_set <char> check;
        for (int right = 0; right < s.size(); right++) {
            while (check.find(s[right]) != check.end()) {
                check.erase(s[left]);
                left++;
            }
            check.insert(s[right]);
            res = max(res, right - left + 1);
        }
        return res;
    }
};

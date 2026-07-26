class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count_t, cur_window;
        for (auto c : t) {
            count_t[c]++;
        }
        int res_len = INT_MAX, l_start = 0;
        int l = 0, r = 0, check_valid = 0;
        while (r < s.size()) {
            cur_window[s[r]]++;
            if (count_t.count(s[r]) and count_t[s[r]] == cur_window[s[r]]) {
                check_valid++;
            }
            while (check_valid == count_t.size()) {
                if (r - l + 1 < res_len) {
                    res_len = r - l + 1;
                    l_start = l;
                }
                cur_window[s[l]]--;
                if (count_t.count(s[l]) and cur_window[s[l]] < count_t[s[l]]) {
                    check_valid--;
                }
                l++;
            }
            r++;
        }
        string res = "";
        return res_len == INT_MAX ? "" : s.substr(l_start, res_len);
    }
};

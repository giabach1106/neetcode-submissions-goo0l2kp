class Solution {
private:
    string check_valid(int len, string &s, unordered_map<char, int> count_t) {
        string res = "";
        for (size_t i = 0; i <= s.size() - len; i++) {
            string cur_string = s.substr(i, len);
            unordered_map<char, int> count_cur;
            for (auto c : cur_string) {
                count_cur[c]++;
            }
            bool check_count = true;
            for (auto [c, v] : count_t) {
                if (v > count_cur[c]) { // valid if count_cur >= count_t
                    check_count = false;
                }
            }
            if (check_count) {
                res = cur_string;
                break;
            }
        }

        return res;
    }
public:
    string minWindow(string s, string t) {
        int left = 1, right = s.size();
        string res = "";
        unordered_map<char, int> count_t;
        for (auto c : t) {
            count_t[c]++;
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            string valid_string = check_valid(mid, s, count_t);
            if (valid_string != "") {
                res = valid_string;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};

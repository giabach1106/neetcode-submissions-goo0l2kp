class Solution {
public:
    string check(int len, string &s, string &t) {
        string res = "";
        unordered_map<char, int> count_t;
        for (auto ch : t) {
            count_t[ch]++;
        }
        for (int i = 0; i <= s.size() - len; i++) {
            string tmp = s.substr(i, len);
            unordered_map<char, int> check;
            for (auto c : tmp) {
                check[c]++;
            }
            bool check_c = true;
            for (auto [c, v] : count_t) {
                if (v > check[c]) {
                    check_c = false;
                }
            }
            if (check_c)
                return tmp;
        }
        return res;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int left = 1, right = n;
        string ans = ""; // length of the ...
        while (left <= right) {
            int mid = (left + right) / 2;
            string res = check(mid, s, t);
            if (res != "") {
                right = mid - 1;
                ans = res;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        string res = s.substr(0, 1);
        int tmp = 1;
        if (s.size() < 2) {
            return s;
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                string ss = s.substr(i, j - i + 1);
                int l = 0, r = ss.size() - 1;
                bool check = false;
                while (l < r) {
                    if (ss[l] != ss[r]) {
                        check = true;
                        break;
                    }
                    l++;
                    r--;
                }
                if (check == false and tmp < ss.size()) {
                    res = ss;
                    tmp = ss.size();
                }
            }
        }
        return res;
    }
};

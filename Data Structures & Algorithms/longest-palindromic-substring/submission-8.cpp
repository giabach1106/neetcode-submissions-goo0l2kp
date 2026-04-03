class Solution {
public:
    string longestPalindrome(string s) {
        string res = s.substr(0, 1);
        int maxRes = 1;
        if (s.size() < 2) {
            return s;
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string ss = s.substr(i, j - i + 1);
                if (ss.size() > maxRes) {
                    int l = 0, r = ss.size() - 1;
                    bool isPali = true;
                    while (l < r) {
                        if (ss[l] != ss[r]) {
                            isPali = false;
                            break;
                        }
                        l++;
                        r--;
                    }
                    if (isPali) {
                        res = ss;
                        maxRes = ss.size();
                    }
                }
            }
        }
        return res;
    }
};
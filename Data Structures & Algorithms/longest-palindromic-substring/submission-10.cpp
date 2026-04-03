class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int maxRes = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] and (j - i <= 2 or dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxRes) {
                        maxRes = j - i + 1;
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return res;
    }
};

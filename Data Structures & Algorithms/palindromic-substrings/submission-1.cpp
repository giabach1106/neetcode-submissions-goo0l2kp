class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >=0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] and (j - i <= 2 or dp[i + 1][j - 1] == true)) {
                    dp[i][j] = true;
                    res++;
                }
            } 
        }
        return res;
    }
};

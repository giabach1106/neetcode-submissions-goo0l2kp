class Solution {
public:
    int numDecodings(string s) {
        // 1 - 9
        // 1 : 0 9
        // 2 : 0 6 
        // s = 12
        // dp : 1 1 1
        // i = 1, > 0:
        //     dp[1] = dp[2] = 1
        //     i = 2 < 2, continue
        // i = 0
        //     dp[0] = dp[1] = 1
        //     1 < 2 and s[0] = 1 
        //         dp[0] += d[2] 
        //         dp[0] = 2
        vector<int> dp(s.size() + 1, 1);
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else {
                dp[i] = dp[i + 1];
                if (i + 1 < s.size() and (s[i] == '1' or (s[i] == '2' and s[i + 1] < '7'))) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};

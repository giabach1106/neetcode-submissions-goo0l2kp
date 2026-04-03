class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (auto w : wordDict) {
                if (dp[i + w.size()] and s.substr(i, w.size()) == w) {
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};

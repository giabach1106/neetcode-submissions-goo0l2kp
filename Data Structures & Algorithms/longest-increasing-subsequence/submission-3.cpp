class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

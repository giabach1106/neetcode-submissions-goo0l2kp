class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, 0));
        dp[nums.size() - 1][0] = nums[nums.size() - 1];
        dp[nums.size() - 1][1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            dp[i][1] = max(nums[i], dp[i + 1][1] + nums[i]);
            dp[i][0] = max(dp[i][1], dp[i + 1][0]);
        }

        return dp[0][0];
    }
};

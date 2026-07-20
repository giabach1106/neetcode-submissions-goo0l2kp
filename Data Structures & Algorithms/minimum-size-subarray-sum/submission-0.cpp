class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int l = 0, r = 0;
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > target) {
                sum -= nums[l];
                res = min(res, r - l + 1);
                l++;
            }
            r++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
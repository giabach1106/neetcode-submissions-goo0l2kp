class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int tmp = 0;
            for (int j = i; j < nums.size(); j++) {
                tmp += nums[j];
                res = max(res, tmp);
            }
        }
        return res;
    }
};

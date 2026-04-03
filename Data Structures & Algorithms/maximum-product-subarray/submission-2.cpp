class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1, curMin = 1, res = -10;
        for (auto num : nums) {
            int tmp = curMax * num;
            curMax = max(max(curMax * num, curMin * num), num);
            curMin = min(min(tmp, curMin * num), num);
            res = max(res, curMax);
        }
        return res;
    }
};

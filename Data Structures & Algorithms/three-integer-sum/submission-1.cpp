class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i - 1 >= 0 and nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[r] + nums[l];
                if (sum < 0)
                    l++;
                else if (sum > 0)
                    r--;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r and nums[l] == nums[l - 1])
                        l++;
                }
            }
        }
        return res;
    }
};

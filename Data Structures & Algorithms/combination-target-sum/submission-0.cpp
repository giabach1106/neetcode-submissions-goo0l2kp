class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (target == 0) {
            ans.push_back(vector<int>());
            return ans;            
        }
        for (int x : nums) {
            if (x > target) continue;
            auto tmp = combinationSum(nums, target - x);
            for (auto y : tmp) {
                if (y.empty() || x >= y.back()) {
                    y.push_back(x);
                    ans.push_back(y);
                }            
            }
        }
        return ans;
    }
};

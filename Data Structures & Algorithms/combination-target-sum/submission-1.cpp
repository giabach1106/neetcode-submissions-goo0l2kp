class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> set;
        dfs(res, nums, target, set, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, int target, vector<int>& set, int i) {
        if (target == 0) {
            res.push_back(set);
            return;
        }
        if (target < 0 or i >= nums.size()){
            return;
        }
        set.push_back(nums[i]);
        dfs(res, nums, target - nums[i], set, i);
        set.pop_back();
        dfs(res, nums, target, set, i+1);
    }
};

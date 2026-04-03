class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(res, subset, nums, target, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int target, int k) {
        if (target == 0) {
            res.push_back(subset);
            return;
        } 
        if (target < 0 or k >= nums.size()) {
            return;
        } 
        subset.push_back(nums[k]);
        dfs(res, subset, nums, target - nums[k], k);
        subset.pop_back();
        dfs(res, subset, nums, target, k + 1);
    }
};

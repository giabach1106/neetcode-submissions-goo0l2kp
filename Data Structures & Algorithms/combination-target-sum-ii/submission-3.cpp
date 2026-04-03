class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(res, subset, candidates, target, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int target, int i) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (target < 0 or i >= nums.size()) {
            return;
        }
        subset.push_back(nums[i]);
        dfs(res, subset, nums, target - nums[i], i+1);
        subset.pop_back();
        while(i + 1 < nums.size() and nums[i] == nums[i+1]) 
            i++;
        dfs(res, subset, nums, target, i + 1);
    }
};

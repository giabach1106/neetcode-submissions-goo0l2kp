class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        vector<bool> picked(nums.size(), false);
        dfs(res, subset, nums, picked);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, vector<bool>& picked) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!picked[i]) {
                picked[i] = true;
                subset.push_back(nums[i]);
                dfs(res, subset, nums, picked);
                subset.pop_back();
                picked[i] = false;
            }
        }
    }
};

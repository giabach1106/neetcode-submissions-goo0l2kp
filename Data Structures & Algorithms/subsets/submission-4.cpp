class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> set;
        dfs(nums, 0, res, set);
        return res;
    }
private:
    void dfs(vector<int>& nums, int i, vector<vector<int>>& res, vector<int>& set) {
        if (i >= nums.size()) {
            res.push_back(set);
            return;
        }
        set.push_back(nums[i]);
        dfs(nums, i+1, res, set);
        set.pop_back();
        dfs(nums, i+1, res, set);
    }
};

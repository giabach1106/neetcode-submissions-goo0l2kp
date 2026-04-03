class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> set;
        dfs(set, res, 0, nums);
        return res;
    }
private:
    void dfs(vector<int>& set, vector<vector<int>>& res, int i, vector<int>& nums) {
        if (i >= nums.size()) {
            res.push_back(set);
            return;
        }
        set.push_back(nums[i]);
        dfs(set, res, i+1, nums);
        set.pop_back();
        dfs(set, res, i+1, nums);
    }
};

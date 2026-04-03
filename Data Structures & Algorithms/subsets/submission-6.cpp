class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(res, subset, nums, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int k) {
        if (k >= nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[k]);
        dfs(res, subset, nums, k + 1);  
        subset.pop_back();
        dfs(res, subset, nums, k + 1);
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> set;
        vector<bool> picked(nums.size(), false);
        dfs(res, set, nums, picked);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& set, vector<int>& nums, vector<bool>& picked ) {
        if (set.size() == nums.size()) {
            res.push_back(set);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!picked[i]) {
                picked[i] = true;
                set.push_back(nums[i]);
                dfs(res, set, nums, picked);
                set.pop_back();
                picked[i] = false;
            }
        }
        
    }
};

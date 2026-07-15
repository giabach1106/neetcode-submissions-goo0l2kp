class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i - 1 >= 0 and nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (j - 1 >= i + 1 and nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    long long sum = nums[i] + nums[j] + nums[l] + nums[r]; 
                    if (sum < target) {
                        l++;
                    }
                    else if (sum > target) {
                        r--;
                    }
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        r--;
                        l++;
                        while (l < r and nums[l] == nums[l - 1])
                            l++;
                        
                    }
                }
            }
        }

        return res;
    }
};
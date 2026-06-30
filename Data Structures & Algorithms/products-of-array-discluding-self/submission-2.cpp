class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res (nums.size());
        int p = 1, z = 0;

        for (auto num : nums) {
            if (num != 0)
                p *= num;
            else
                z++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (z > 1)  
                res[i] = 0;
            else if (z == 1)
                res[i] = (nums[i] == 0) ? p : 0;
            else res[i] = p / nums[i];
        }
        return res;
    }
};

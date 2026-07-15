class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = tmp[(i + k)% nums.size()];
        } 
    }
};
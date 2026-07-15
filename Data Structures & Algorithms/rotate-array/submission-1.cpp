class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        l += k % nums.size();
        r = (r + k) % nums.size();
        // l = 4
        // r = 3
        vector<int> tmp(nums.begin(), nums.end());
        for (int i = 0; i <= r; i++) {
            nums[i] = tmp[(i + l) % nums.size()];
        } 
        for (int i = l; i < nums.size(); i++) {
            nums[i] = tmp[(i - l) % nums.size()];
        }
    }
};
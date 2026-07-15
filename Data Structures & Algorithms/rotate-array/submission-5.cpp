class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp(nums.begin(), nums.end());
        if (nums.size() % 2 == 0) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = tmp[(i + k) % nums.size()];
            }
        } 
        else {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = tmp[(i + k - 1) % nums.size()];
            }
        }
    }
};
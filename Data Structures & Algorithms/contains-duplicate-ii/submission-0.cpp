class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0, r = 1;
        while (r < nums.size()) {
            if (nums[l] == nums[r])
                return true;
            r++;
            if (r - l > k)
                l++;
        }
        return false;
    }
};
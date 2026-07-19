class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (j - i > k) {
                s.erase(nums[i]);
                i++;
            }
            if (s.count(nums[j]))
                return true;
            s.insert(nums[j]);
            j++;
        }
        return false;
    }
};
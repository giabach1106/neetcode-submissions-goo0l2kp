class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] += 1;
        }
        int res = INT_MIN, result;
        for (auto [x, y] : m) {
            if (res < y) {
                res = y;
                result = x;
            } 
        }
        return result;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }
        vector<int> res;
        for (auto [x, y] : m) {
            if (y > nums.size() / 3) {
                res.push_back(x);
            }
        }
        return res;
    }
};
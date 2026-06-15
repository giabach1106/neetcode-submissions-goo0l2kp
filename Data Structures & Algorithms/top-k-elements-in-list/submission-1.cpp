class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }
        for (auto [x, y] : m) {
            if (k == 0)
                break;
            res.push_back(x);
            k--;
        }
        return res;
    }
};

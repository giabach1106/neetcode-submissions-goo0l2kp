class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        vector<pair<int, int>> p;
        for (auto [x, y] : m) {
            p.push_back({x, y});
        }
        sort(p.rbegin(), p.rend());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(p[i].first);
        }
        return res;
    }
};

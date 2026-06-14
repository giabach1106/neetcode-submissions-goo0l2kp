class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0);
            for (auto c : strs[i]) {
                count[c - 'a']++;
            }
            string s = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                s += "," + to_string(count[i]);
            }
            m[s].push_back(strs[i]);
        }
        for (auto [x, y] : m) {
            res.push_back(y);
        }
        return res;
    }
};

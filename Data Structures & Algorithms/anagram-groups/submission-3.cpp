class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());

            if (m.count(tmp)) {
                m[tmp].push_back(strs[i]);
            }
            else {
                vector<string> a = {strs[i]};
                m[tmp] = a;
            }
        }
        for (auto [a, b] : m) {
            res.push_back(b);
        }

        return res;
    }
};

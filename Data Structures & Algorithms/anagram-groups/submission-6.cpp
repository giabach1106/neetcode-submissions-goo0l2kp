class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto str : strs) {
            vector<int> count(26, 0);
            for (auto c : str) {
                count[c - 'a']++;
            } 
            string s = "";
            for (int i = 0; i < 26; i++) {
                s += ',' + to_string(count[i]);
            }
            m[s].push_back(str);
        }
        vector<vector<string>> res;
        for (auto [x, y] : m) {
            res.push_back(y);
        }
        return res;
    }
};

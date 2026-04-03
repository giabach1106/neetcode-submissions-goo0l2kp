class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            res[str].push_back(strs[i]);
        }
        for (auto& i : res) {
            result.push_back(i.second);
        }
        return result;
    }
};

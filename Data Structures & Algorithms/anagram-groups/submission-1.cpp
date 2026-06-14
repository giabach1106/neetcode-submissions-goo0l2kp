class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            bool check = false;
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            for (auto& group : res) {
                string ss = group[0];
                sort(ss.begin(), ss.end());
                if (ss == tmp) {
                    group.push_back(strs[i]);
                    check = true;
                    break;
                }
            }
            if (!check) {
                vector<string> a = {strs[i]};
                res.push_back(a);
            }
        }
        return res;
    }
};

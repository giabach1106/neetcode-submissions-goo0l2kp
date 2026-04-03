class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subset;
        dfs(res, subset, s, 0);
        return res;
    }
private:
    void dfs(vector<vector<string>>& res, vector<string>& subset, string s, int i) {
        if (i >= s.size()) {
            res.push_back(subset);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (isP(i, j, s)) {
                subset.push_back(s.substr(i, j - i + 1));
                dfs(res, subset, s, j + 1);
                subset.pop_back();
            }
        } 
    }
    bool isP(int i, int j, string s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

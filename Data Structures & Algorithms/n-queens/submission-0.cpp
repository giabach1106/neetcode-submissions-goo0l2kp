class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s = "";
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        vector<string> subset (n, s);
        vector<bool> row (n, false);
        vector<bool> pos (2 * n, false);
        vector<bool> neg (2 * n, false);

        dfs(res, subset, row, pos, neg, n, 0);
        return res;
    }
private:
    void dfs(vector<vector<string>>& res, vector<string>& subset, vector<bool>& row, vector<bool>& pos, vector<bool>& neg, int n, int i) {
        if (i == n) {
            res.push_back(subset);
            return;
        }
        for (int id = 0; id < n; id++) {
            if (row[id] or pos[id + i] or neg[i - id + n]) {
                continue;
            }
            row[id] = true;
            pos[id + i] = true;
            neg[i - id + n ] = true;
            subset[i][id] = 'Q';
            dfs(res, subset, row, pos, neg, n, i + 1);
            row[id] = false;
            pos[id + i] = false;
            neg[i - id + n] = false;
            subset[i][id] = '.';
        }
    }
};

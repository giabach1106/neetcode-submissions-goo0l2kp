class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j, 1));
                }
            }
        }
        return res;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int count) {
        if (i < 0 or j < 0 or
            i >= grid.size() or j >= grid[i].size() or
            grid[i][j] == 0) {
                return 0;
        }
        grid[i][j] = 0;
        count = max(count, dfs(grid, i + 1, j, count + 1));
        count = max(count, dfs(grid, i, j + 1, count + 1));
        count = max(count, dfs(grid, i - 1, j, count + 1));
        count = max(count, dfs(grid, i, j - 1, count + 1));
        return count;
    }
};

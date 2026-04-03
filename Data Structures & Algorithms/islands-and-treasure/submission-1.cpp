class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == INF) {
                    grid[i][j] = bfs(grid, i , j);
                    
                }
            }
        }
    }
private:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int INF = 2147483647;
        queue<pair<int, int>> q;
        q.push({i,j});
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        visited[i][j] = true;
        int res = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [row, col] = q.front();
                q.pop();
                if (grid[row][col] == 0)
                    return res;
                vector<vector<int>> dir = {{0, 1}, {0, -1}, 
                                           {1, 0}, {-1, 0}};
                for (auto& tmp : dir) {
                    int nrow = row + tmp[0];
                    int ncol = col + tmp[1];
                    if (nrow >= 0 and nrow < grid.size() and
                        ncol >= 0 and ncol < grid[0].size() and
                        grid[nrow][ncol] != -1 and visited[nrow][ncol] == false) {
                            visited[nrow][ncol] = true;
                            q.push({nrow, ncol});
                        }
                }
            }
            res++;
        }
        return INF;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)    
                    fresh++;
                if (grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int res = 0;
        vector<pair<int,int>> directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty() and fresh > 0) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                auto rotten = q.front();
                q.pop();
                int r = rotten.first;
                int c = rotten.second;
                for (auto direction : directions) {
                    int row = r + direction.first;
                    int column = c + direction.second;
                    if (row < grid.size() and row >= 0 and 
                      column < grid[0].size() and column >= 0 and
                      grid[row][column] == 1) {
                            grid[row][column] = 2;
                            q.push({row, column});
                            fresh--;
                    }
                }
            }
            res++;
        }
        return fresh == 0 ? res : -1;
    }
};

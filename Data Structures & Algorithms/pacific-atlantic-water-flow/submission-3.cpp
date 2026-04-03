class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> visitP (heights.size(), vector<bool> (heights[0].size(), false));
        vector<vector<bool>> visitA (heights.size(), vector<bool> (heights[0].size(), false));
        queue<pair<int, int>> qP, qA;
        for (int i = 0; i < heights.size(); i++){
            qP.push({i, 0});
            qA.push({i, heights[0].size() - 1});
            visitP[i][0] = true;
            visitA[i][heights[0].size() -  1] = true;
            // pacific = 0 0, 0 1, 0 2, 0 3
                 //    = 0 0, 1 0, 2 0
        }
        for (int i = 0; i < heights[0].size(); i++) {
            qP.push({0, i});
            qA.push({heights.size() - 1, i});
            visitP[0][i] = true;
            visitA[heights.size() - 1][i] = true;
        }
        // atlantic = 2 0, 2 1, 2 2, 2 3, 2 4, 2 5
            //      = 0 4, 1 4, 2 4
        bfs(heights, qP, visitP);
        bfs(heights, qA, visitA);
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (visitP[i][j] and visitA[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
private:
    void bfs (vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;
            for (auto dir : directions) {
                int nrow = r + dir.first;
                int ncol = c + dir.second;
                if (nrow >= 0 and nrow < heights.size() and
                    ncol >= 0 and ncol < heights[0].size() and
                    visited[nrow][ncol] == false and 
                    heights[nrow][ncol] >= heights[r][c]) {
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
            }
        }
    }
};

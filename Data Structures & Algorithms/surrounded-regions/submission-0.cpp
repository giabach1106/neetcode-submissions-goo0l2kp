class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O' and visited[i][0] == false) {
                visited[i][0] = true;
                q.push({i, 0});
            }
            if (board[i][board[0].size() - 1] == 'O' and visited[i][board[0].size() - 1] == false) {
                q.push({i, board[0].size() - 1});
                visited[i][board[0].size() - 1] = true;
            }
        }        
        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O' and visited[0][i] == false) {
                q.push({0, i});
                visited[0][i] = true;
            }
            if (board[board.size() - 1][i] == 'O' and visited[board.size() - 1][i] == false) {
                q.push({board.size() - 1, i});
                visited[board.size() - 1][i] = true;
            }

        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;
            for (auto dir : directions) {
                int nrow = r + dir.first;
                int ncol = c + dir.second;
                if (nrow >= 0 and nrow < board.size() and
                    ncol >= 0 and ncol < board[0].size() and
                    visited[nrow][ncol] == false and
                    board[nrow][ncol] == 'O') {
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O' and visited[i][j] == false)
                    board[i][j] = 'X';
            }
        }
    }
};

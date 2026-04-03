class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited (board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
            if (dfs(board, word, i, j, 0, visited)) {
                return true;
            }
            }
        }
        return false;

    }
private:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int n, vector<vector<bool>>& visited) {
        if (n == word.size()) {
            return true;
        }
        if (i >= board.size() or j >= board[0].size() or
            i < 0 or j < 0 or
            board[i][j] != word[n] or
            visited[i][j] == true) {
                return false;
            }
        visited[i][j] = true;
        bool res = dfs(board, word, i - 1, j, n + 1, visited) or
                   dfs(board, word, i + 1, j, n + 1, visited) or
                   dfs(board, word, i, j - 1, n + 1, visited) or
                   dfs(board, word, i, j + 1, n + 1, visited);
        visited[i][j] = false;
        return res;
    }
};

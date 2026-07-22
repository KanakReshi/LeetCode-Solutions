class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        vector<int> dir = {0, 1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k];
            int nc = j + dir[k + 1];
            if (nc < 0 || nr < 0 || nr >= m || nc >= n)
                continue;
                if(board[nr][nc] != 'O')continue;
            board[nr][nc] = '#';
            dfs(board, nr, nc);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'X' || board[i][0] == '#')
                continue;
            else {
                board[i][0] = '#';
                dfs(board, i, 0);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'X' || board[0][i] == '#')
                continue;
            else {
                board[0][i] = '#';
                dfs(board, 0, i);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'X' || board[i][n - 1] == '#')
                continue;
            else {
                board[i][n - 1] = '#';
                dfs(board, i, n - 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[m - 1][i] == 'X' || board[m - 1][i] == '#')
                continue;
            else {
                board[m - 1][i] = '#';
                dfs(board, m - 1, i);
            }
        }
        for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 'O')
                        board[i][j] = 'X';
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == '#')
                        board[i][j] = 'O';
                }
            }
    }
};
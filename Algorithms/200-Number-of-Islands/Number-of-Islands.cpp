class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        grid[i][j] = '0';
        q.push({i, j});
        while (q.size()) {
            auto [x,y] = q.front();
            q.pop();
            vector<int> dir = {0, 1, 0, -1, 0};
            for (int k = 0; k < 4; k++) {
                int nr = x + dir[k];
                int nc = y + dir[k + 1];
                if (nr < 0 || nr > m - 1 || nc < 0 || nc > n - 1 ||grid[nr][nc] == '0')continue;
                grid[nr][nc] = '0';
                q.push({nr, nc});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // vector<vector<int>>visited(m,vector<int>(n,-1));
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    result++;
                    bfs(grid, i, j);
                }
            }
        }
        return result;
    }
};
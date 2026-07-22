class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 1)
            grid[i][j] = '#';
        else
            return;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dir = {0, 1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k];
            int nc = j + dir[k + 1];
            if (nc < 0 || nr < 0 || nc >= n || nr >= m || grid[nr][nc] == '#')
                continue;
            dfs(grid, nr, nc);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // for(int i = 0 ; i < m ;i++){
        //     if(grid[i][0] == 1)dfs(grid,i,0);
        //     if(grid[i][n-1] == 1)dfs(grid,i,n-1);
        // }
        // for(int i = 0 ; i < n ;i++){
        //     if(grid[0][i] == 1)dfs(grid,0,i);
        //     if(grid[m-1][i] == 1)dfs(grid,m-1,i);
        // }

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0 || grid[i][0] == '#')
                continue;
            else
                dfs(grid, i, 0);
        }
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 0  || grid[0][i] == '#')
                continue;
            else
                dfs(grid, 0, i);
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][n - 1] == 0 || grid[i][n - 1] == '#')
                continue;
            else
                dfs(grid, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            if (grid[m - 1][i] == 0 || grid[m - 1][i] == '#')
                continue;
            dfs(grid, m - 1, i);
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    result++;
            }
        }
        return result;
    }
};
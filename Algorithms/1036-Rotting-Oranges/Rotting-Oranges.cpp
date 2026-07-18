class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int result = 0;
        while (!q.empty()) {
            result++;
            int k = q.size();
            for (int i = 0; i < k; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if (row - 1 >= 0 && !(visited[row-1][col]) && grid[row-1][col]) {
                visited[row-1][col] = true;
                grid[row-1][col] = 2;
                q.push({row-1,col});
            }
            if (col - 1 >= 0 && !(visited[row][col-1]) && grid[row][col-1] == 1) {
                visited[row][col-1] = true;
                grid[row][col-1] = 2;
                q.push({row,col-1});
            }
            if (row + 1 < m && !(visited[row+1][col]) && grid[row+1][col]){
                visited[row+1][col] = true;
                grid[row+1][col] = 2;
                q.push({row+1,col});
            }
            if (col + 1 < n && !(visited[row][col+1]) && grid[row][col+1]) {
                visited[row][col+1] = true;
                grid[row][col+1] = 2;
                q.push({row,col+1});
            }
            }
        }
        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ; j < n ;j++){
                if(grid[i][j] == 1)return -1;
            }
        }
        if(result==-1)return -1;
        else if(result==0)return 0;
        else return result-1;
    }
    };
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> temp = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int initial = image[sr][sc];
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            temp[row][col] = color;
            if (row > 0 && temp[row - 1][col] != color && temp[row - 1][col] == initial ) {
                temp[row - 1][col] = color;
                q.push({row - 1, col});
            }
            if (col > 0 && temp[row][col-1] != color && temp[row][col-1] == initial) {
                temp[row][col - 1] = color;
                q.push({row, col - 1});
            }
            if (row < m-1 && temp[row + 1][col] != color && temp[row + 1][col] == initial) {
                temp[row + 1][col] = color;
                q.push({row + 1, col});
            }
            if (col < n-1 && temp[row][col+1] != color && temp[row][col+1] == initial) {
                temp[row][col + 1] = color;
                q.push({row, col + 1});
            }
        }
        return temp;
    }
};
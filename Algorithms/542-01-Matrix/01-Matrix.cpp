class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>q;
        for(int i = 0 ;i < m ;i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }

        while(q.size()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<int>dir = {0,1,0,-1,0};
            for(int i = 0 ; i < 4;i++){
                int new_row = dir[i] + row;
                int new_col = dir[i+1] + col;
                if(new_row < 0  || new_col < 0 || new_row >= m || new_col >= n || mat[new_row][new_col] != -1)continue;
                mat[new_row][new_col] = mat[row][col] + 1;
                q.push({new_row , new_col});
            }
        }
        return mat;
    }
};
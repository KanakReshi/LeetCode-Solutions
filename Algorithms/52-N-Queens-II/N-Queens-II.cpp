class Solution {
     bool check(int row,int col , vector<string> &board , vector<vector<string>> &result , int n){
        int temp_row = row;
        int temp_col = col;
        while(temp_col >= 0){
            if(board[row][temp_col] == 'Q')return false;
            temp_col--;
        }
        temp_col = col;
        while(temp_row>=0 && temp_col>=0){
            if(board[temp_row][temp_col] == 'Q')return false;
            temp_row--;
            temp_col--;
        }
        temp_row = row;
        temp_col = col;
        while(temp_row< n && temp_col>=0){
            if(board[temp_row][temp_col] == 'Q')return false;
            temp_row++;
            temp_col--;
        }
        return true;
    }

    void create(int col, vector<string> &board , vector<vector<string>> &result,int n){
        if(col==n){
            result.push_back(board);
            return;
        }
        for(int i = 0 ; i < n ;i++){
            if(check(i,col,board,result,n)){
                board[i][col] = 'Q';
                create(col+1,board,result,n);
                board[i][col] = '.';
            }
        }

    }
public:
    int totalNQueens(int n) {
        vector<vector<string>>result;
        vector<string> board(n, string(n,'.'));
        create(0,board,result,n);
        return result.size();
    }
};
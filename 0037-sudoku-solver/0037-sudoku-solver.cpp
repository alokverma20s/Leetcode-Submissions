class Solution {
    bool check(vector<vector<char>>& board, int row, int col, char v){
        for(int i=0; i<9; i++){
            if(board[row][i] == v) return false;
            if(board[i][col] == v) return false;
            if(board[3 * (row/3) + i/3][3 * (col/3) +i%3] == v) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9 ;i++){
            for(int j=0; j< 9; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c <= '9'; c++){
                        if(check(board, i, j, c)){
                            board[i][j] = c;
                            // cout<<1<<endl;
                            if(solve(board) == true) return true;
                            else board[i][j] ='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
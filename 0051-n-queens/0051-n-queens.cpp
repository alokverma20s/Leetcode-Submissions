class Solution {
    bool isSafe(int row, int col, vector<string> &board, int n){
        int duprow = row;
        int dupcol = col;

        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row= duprow;
        col = dupcol;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        col = dupcol;
        while(col>=0 && row < n){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string> board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] ='Q';
                solve(col+1, board, ans, n);
                board[row][col] ='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);

        solve(0, board, ans, n);
        return ans;
    }
};
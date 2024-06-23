class Solution {
    void solve(int col, vector<string> board, vector<vector<string>> &ans, int n, vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(!leftRow[row] && !upperDiagonal[(n-1) + (row-col)] && !lowerDiagonal[row+col]){
                board[row][col] ='Q';
                leftRow[row] = true;
                upperDiagonal[(n-1) + (row-col)] = true;
                lowerDiagonal[row + col] = true;
                solve(col+1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
                board[row][col] ='.';
                leftRow[row] = false;
                upperDiagonal[(n-1) + (row-col)] = false;
                lowerDiagonal[row + col] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        vector<bool> leftRow(n, false);
        vector<bool> lowerDiagonal(2*n-1, false);
        vector<bool> upperDiagonal(2*n-1, false);
        solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};
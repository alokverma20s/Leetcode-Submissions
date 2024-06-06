class Solution {
    int dirx[4]= {1, 0, 0, -1};
    int diry[4] = {0, 1, -1, 0};
    void dfs(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &vis, int &n, int &m){
        if(board[x][y] == 'X')
            return;
        
        vis[x][y] = true;
        
        for(int i=0; i< 4; i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];

            if(nx >= 0 && nx < n && ny >=0 && ny < m){
                if(vis[nx][ny] == false && board[nx][ny] == 'O')
                    dfs(nx, ny, board, vis, n, m);
            }
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board, vis, n, m);
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][m-1] == 'O'){
                dfs(i, m-1, board, vis, n, m);
            }
        }
        for(int i=0; i<m; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, board, vis, n, m);
            }
        }
        for(int i=0; i<m; i++){
            if(board[n-1][i] == 'O'){
                dfs(n-1, i, board, vis, n, m);
            }
        }
        for(int i=0; i< n; i++){
            for(int j=0; j< m; j++){
                if(board[i][j] == 'O' && vis[i][j] == false)
                    board[i][j] = 'X';
            }
        }
    }
};
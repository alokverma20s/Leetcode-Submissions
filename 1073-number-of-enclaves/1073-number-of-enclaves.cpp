class Solution {
    int dirx[4] = {1, 0, 0, -1};
    int diry[4] = {0, 1, -1, 0};
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &n, int &m){
        vis[x][y] = true;

        for(int i =0; i< 4; i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];

            if(nx < n && nx >=0 && ny < m && ny >= 0){
                if(vis[nx][ny] == false && grid[nx][ny] == 1){
                    dfs(nx, ny, grid, vis, n, m);
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // for(auto i: grid){
        //     for(int j: i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;

        for(int i = 0; i<n; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, grid, vis, n, m);
            }
        }
        for(int i = 0; i<n; i++){
            if(grid[i][m-1] == 1){
                dfs(i, m-1, grid, vis, n, m);
            }
        }
        // cout<<endl<<endl;
        for(int i = 0; i<m; i++){
            if(grid[0][i] == 1){
                dfs(0, i, grid, vis, n, m);
            }
        }
        for(int i = 0; i<m; i++){
            if(grid[n-1][i] == 1){
                dfs(n-1, i, grid, vis, n, m);
            }
        }
        int cnt=0;
        for(int i=0; i< n; i++){
            for( int j =0; j <m; j++){
                // cout<< vis[i][j] <<" ";
                if(vis[i][j] == false && grid[i][j] == 1)
                    cnt++;
            }
            // cout<<endl;
        }
        return cnt;
    }
};
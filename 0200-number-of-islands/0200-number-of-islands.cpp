class Solution {
    void bfs(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &vis){
        int dx[]={0,1, 0, -1};
        int dy[]={1, 0, -1, 0};
        vis[x][y]= 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});

        while(!q.empty()){
            pair<int,int> t = q.front();
            q.pop();
            int nx = t.first;
            int ny = t.second;

            for(int i=0; i<4; i++){
                int newx = nx + dx[i];
                int newy = ny + dy[i];

                if(newx >=0 && newx < n && newy >= 0 && newy < m){
                    // cout<< newx<<" "<<newy<<endl;
                    if(vis[newx][newy] == 0 && grid[newx][newy] == '1'){
                        q.push({newx, newy});
                        vis[newx][newy] = 1;
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m , 0));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j< m; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){

                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};
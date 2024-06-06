class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i< n; i++){
            for(int j =0; j< m ;j++){
                if(mat[i][j] == 0)
                    q.push({{i, j}, 0});
            }
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> ans(n, vector<int>(m));
        int dirx[] = {1, 0, 0, -1};
        int diry[] = {0, 1, -1, 0};

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;

            int t = q.front().second;

            q.pop();

            ans[x][y] = t;

            for(int i=0 ;i< 4; i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];

                if(nx < n && nx >= 0 && ny < m && ny >= 0){
                    if(vis[nx][ny] == false && mat[nx][ny] == 1){
                        q.push({{nx, ny}, t+1});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        return ans;
    }
};